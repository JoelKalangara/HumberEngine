#include "HumberEngine.h"

std::unique_ptr<HumberEngine> HumberEngine::engineInstance = nullptr;

HumberEngine::HumberEngine():window(nullptr), isRunning(false),fps(60), timer(nullptr), gameInterface(nullptr), currentSceneNum(0)
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
	Debug::OnCreate();
	window = new Window();
	if (!window->OnCreate(name_,width_,height_))
	{
		//std::cout << "Window failed to initialize" << std::endl;
		Debug::FatalError("Window failed to initialize", "HumberEngine.cpp", __LINE__);
		OnDestroy();
		return isRunning = false;
	}

	ShaderHandler::GetInstance()->CreateProgram("colourShader", "Engine/Shaders/ColourVertexShader.glsl", "Engine/Shaders/ColourFragmentShader.glsl");

	if (gameInterface)
	{
		if (!gameInterface->OnCreate())
		{
			//std::cout << "Game failed to initialize" << std::endl;
			Debug::FatalError("Game failed to initialize", "HumberEngine.cpp", __LINE__);
			OnDestroy();
			return isRunning = false;
		}
	}
	//test purpose
	Debug::Info("Everthing worked", "HumberEngine.cpp", __LINE__);
	timer = new Timer();
	timer->Start();
	return isRunning = true;
}

void HumberEngine::Run()
{
	while (isRunning)
	{
		timer->UpdateFrameTicks();
		Update(timer->GetDeltaTime());
		Render();
		SDL_Delay(timer->GetSleepTime(fps));
	}
	//if (!isRunning){
		OnDestroy();
	//}
}

void HumberEngine::Exit()
{
	isRunning = false;
}

bool HumberEngine::GetIsRunning() const
{
	return isRunning;
}

int HumberEngine::GetCurrentScene() const
{
	return currentSceneNum;
}

float HumberEngine::GetScreenWidth() const
{
	return static_cast<float>(window->GetWidth());
}

float HumberEngine::GetScreenHeight() const
{
	return static_cast<float>(window->GetHeight());
}

Camera* HumberEngine::GetCamera() const
{
	return camera;
}

void HumberEngine::SetGameInterface(GameInterface* gameInterface_)
{
	gameInterface = gameInterface_;
}

void HumberEngine::SetCurrentScene(int sceneNum_)
{
	currentSceneNum = sceneNum_;
}

void HumberEngine::SetCamera(Camera* camera_)
{
	camera = camera_;
}

void HumberEngine::Update(const float deltaTime_)
{
	if (gameInterface)
	{
		gameInterface->Update(deltaTime_);
	}
}

void HumberEngine::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (gameInterface)
	{
		gameInterface->Render();
	}
	//CALL GAME RENDER
	SDL_GL_SwapWindow(window->GetWindow());
}

void HumberEngine::OnDestroy()
{
	//always destroy from the inside out

	ShaderHandler::GetInstance()->OnDestroy();

	delete gameInterface;
	gameInterface = nullptr;

	delete camera;
	camera = nullptr;

	delete window;
	window = nullptr;

	SDL_Quit();
	exit(0);
}
