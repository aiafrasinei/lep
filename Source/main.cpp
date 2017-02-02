#include "App.h"


using namespace Leadwerks;

    #ifdef __APPLE__
int main_(int argc,const char *argv[])
{
	#else
int main(int argc,const char *argv[])
{
	#endif

/*#ifdef _WIN32
	//Enable low-fragmentation heap
	HANDLE heaps[1025];
	DWORD nheaps = GetProcessHeaps((sizeof(heaps) / sizeof(HANDLE)) - 1, heaps);
	for (DWORD i = 0; i < nheaps; ++i) {
		ULONG  enableLFH = 2;
		HeapSetInformation(heaps[i], HeapCompatibilityInformation, &enableLFH, sizeof(enableLFH));
	}
#endif*/

	//Load saved settings
	std::string settingsfile = std::string(argv[0]);
	settingsfile = FileSystem::StripAll(settingsfile);
	if (String::Right(settingsfile, 6) == ".debug") settingsfile = String::Left(settingsfile, settingsfile.length() - 6);
	System::AppName = settingsfile;
	std::string settingsdir = FileSystem::GetAppDataPath();
#ifdef __linux__
	#ifndef __ANDROID__
		settingsdir = settingsdir + "/." + String::Lower(settingsfile);
	#else
		settingsdir = settingsdir + "/" + settingsfile;
	#endif
#else
	settingsdir = settingsdir + "/" + settingsfile;
#endif
	if (FileSystem::GetFileType(settingsdir) == 0) FileSystem::CreateDir(settingsdir);
	settingsfile = settingsdir + "/" + settingsfile + ".cfg";
	System::LoadSettings(settingsfile);

	//Set program path
	System::AppPath = FileSystem::ExtractDir(argv[0]);

	//Load command-line parameters
	System::ParseCommandLine(argc, argv);

	//Enable Lua sandboxing
	if (String::Int(System::GetProperty("sandbox")) != 0) Interpreter::sandboxmode = true;

	//Switch directory
	std::string gamepack = System::GetProperty("game");
	if (gamepack != "")
	{
		Package* package = Package::Load(gamepack);
		if (!package) return 1;
	}

    //Load any zip files in main directory
    Leadwerks::Directory* dir = Leadwerks::FileSystem::LoadDir(".");
    if (dir)
    {
        for (int i=0; i<dir->files.size(); i++)
        {
            std::string file = dir->files[i];
			std::string ext = Leadwerks::String::Lower(Leadwerks::FileSystem::ExtractExt(file));
            if (ext=="zip" || ext=="pak")
            {
                Leadwerks::Package::Load(file);
            }
        }
        delete dir;
    }

		//Execute mobile-style App script
		App* app = new App;
		if (app->Start())
		{
			while (app->Loop()) {}

			//Save settings
			delete app;
			if (!System::SaveSettings(settingsfile)) System::Print("Error: Failed to save settings file \"" + settingsfile + "\".");
			System::Shutdown();
			return 0;
		}
		else
		{
			return 1;
		}
}
