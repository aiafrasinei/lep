#include "App.h"

using namespace Leadwerks;

App::App() : window(NULL), context(NULL), world(NULL), camera(NULL) {}

App::~App() { delete world; delete window; }

Model* model = NULL;

bool App::Start()
{
	//Create a window
	window = Window::Create();

	context = Context::Create(window);
	world = World::Create();
	camera = Camera::Create();
	camera->Move(0, 0, -3);
	Light* light = DirectionalLight::Create();
	light->SetRotation(35, 35, 0);

	//Create a model
	model = Model::Box();
	model->SetColor(0.0, 0.0, 1.0);

	return true;
}

bool App::Loop()
{
	if (window->Closed() || window->KeyDown(Key::Escape)) return false;

	model->Turn(0, Time::GetSpeed(), 0);

	Time::Update();
	world->Update();
	world->Render();
	context->Sync(false);

	return true;
}