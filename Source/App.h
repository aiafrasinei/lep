#ifndef __S_LEP_APP_H__
#define __S_LEP_APP_H__

#include "Leadwerks.h"

#undef GetFileType

using namespace Leadwerks;

class App
{
private:
        bool running = true;
        long tick;
public:
	Leadwerks::Window* window;
	Context* context;
	World* world;
	Camera* camera;
    
	App();
	virtual ~App();

    bool Start();
    bool Loop();
};

#endif
