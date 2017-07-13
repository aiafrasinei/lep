#include "Leadwerks.h"

using namespace Leadwerks;


Model* model = NULL;

int main(int argc, const char *argv[])
{
	Leadwerks::Window* window = Leadwerks::Window::Create();
        Context* context = Context::Create(window);
        World* world = World::Create();
        Camera* camera = Camera::Create();
        camera->Move(0,0,-3);
        Light* light = DirectionalLight::Create();
        light->SetRotation(35,35,0);
        
        //Create a model
        model = Model::Box();
        model->SetColor(0.0,0.0,1.0);

        while (true)
        {
                if (window->Closed() || window->KeyDown(Key::Escape)) return false;
    
                model->Turn(0,Leadwerks::Time::GetSpeed(),0);

                Leadwerks::Time::Update();
                world->Update();
                world->Render();
                context->Sync(false);

        }
        return 0;
}
