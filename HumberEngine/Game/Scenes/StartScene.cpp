#include "StartScene.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

bool StartScene::OnCreate()
{
	//std::cout << "start scene" << std::endl;
	Debug::Info("Creating StartScene", "StartScene.cpp", __LINE__);
	return true;
}

void StartScene::Update(const float deltaTime_)
{
	HumberEngine::GetInstance()->SetCurrentScene(1);
}

void StartScene::Render()
{
}
