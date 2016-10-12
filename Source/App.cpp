#define _GLIBCXX_USE_CXX11_ABI 0

#include "App.h"

using namespace Leadwerks;


App::App() : window(NULL), context(NULL), world(NULL), camera(NULL) {}

App::~App() { delete world; delete window; }

bool vs = false;

bool App::Start()
{
//GAME BASIC INITIALIZATION
        System::Print("lep start\n");
        
        tick = 0;
        
        int WindowFlags = 0;
        WindowFlags = Leadwerks::Window::Titlebar;
        vs = true;
        
        window = Leadwerks::Window::Create("lep", 0, 0, 1024, 768, WindowFlags);
        
        context = Context::Create(window);
        world = World::Create();
        
        camera = Camera::Create();
        camera->SetPosition(2, 3, -1);
		camera->SetClearColor(0.1, 0.1, 0.2);


//GAME SPECIFIC
        Light* light1 = DirectionalLight::Create();
        light1->SetPosition(100, 100, 0);
        light1->SetColor(2.9,2.9,3.0);
        
        world->SetAmbientLight(1.0,1.0,1.18);
        //window->HideMouse();
         
	return true;
}

bool App::Loop()
{
        Leadwerks::Time::Update();
        
        world->Update();
        world->Render();
                
        context->Sync(vs);

	return true;
}
