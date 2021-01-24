#include "HumberEngine.h"

std::unique_ptr<HumberEngine> HumberEngine::engineInstance = nullptr;

HumberEngine::HumberEngine():window(nullptr), isRunning(false)
{
}

HumberEngine::~HumberEngine()
{
}

HumberEngine* HumberEngine::GetInstance()
{
	if (engineInstance.get()==nullptr)
	{
		engineInstance.reset(new HumberEngine);
	}
	return engineInstance.get();
}

bool HumberEngine::OnCreate(std::string name_, int width_, int height_)
{
	window = new Window();
	if (!window->OnCreate(name_,width_,height_))
	{
		std::cout << "Window failed to initialize" << std::endl;
		OnDestroy();
		return isRunning = false;
	}
	return isRunning = true;
}

void HumberEngine::Run()
{
	while (isRunning)
	{
		Update(0.016f);
		Render();
	}
	//if (!isRunning){
		OnDestroy();
	//}
}

bool HumberEngine::GetIsRunning()
{
	return isRunning;
}

void HumberEngine::Update(const float deltaTime_)
{
}

void HumberEngine::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//CALL GAME RENDER
	SDL_GL_SwapWindow(window->GetWindow());
}

void HumberEngine::OnDestroy()
{
	delete window;
	window = nullptr;
	SDL_Quit();
	exit(0);
}
