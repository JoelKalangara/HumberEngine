#include "Game1.h"

Game1::Game1():GameInterface(), currentSceneNum(0), currentScene(nullptr)
{
}

Game1::~Game1()
{
	delete currentScene;
	currentScene = nullptr;
}

bool Game1::OnCreate()
{
	if (HumberEngine::GetInstance()->GetCurrentScene()==0)
	{
		currentScene = new StartScene();
		currentSceneNum = 0;
		return currentScene->OnCreate();
	}
	//std::cout << "Engine's scene is not initialized to 0" << std::endl;
	Debug::Error("Engine's scene is not initialized to 0", "Game1.cpp", __LINE__);
	return false;
}

void Game1::Update(const float deltaTime_)
{
	if (currentSceneNum != HumberEngine::GetInstance()->GetCurrentScene())
	{
		BuildScene();
	}
	currentScene->Update(deltaTime_);
}

void Game1::Render()
{
	currentScene->Render();
}

void Game1::BuildScene()
{
	delete currentScene;
	currentScene = nullptr;

	switch (HumberEngine::GetInstance()->GetCurrentScene())
	{
	case 1:
		currentScene = new GameScene();
		break;
	default: //case 0:
		currentScene = new StartScene();
		break;
	}

	currentSceneNum = HumberEngine::GetInstance()->GetCurrentScene();
	if (!currentScene->OnCreate())
	{
		//std::cout << "Scene failed to be created" << std::endl;
		Debug::Error("Scene failed to be created", "Game1.cpp", __LINE__);
		
		HumberEngine::GetInstance()->Exit();
	}
}
