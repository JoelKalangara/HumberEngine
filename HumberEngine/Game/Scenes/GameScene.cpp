#include "GameScene.h"

GameScene::GameScene(): shape(nullptr)
{
}

GameScene::~GameScene()
{
	delete shape;
	shape = nullptr;
}

bool GameScene::OnCreate()
{
	//std::cout << "game scene" << std::endl;
	Debug::Info("Creating GameScene", "GameScene.cpp", __LINE__);

	Vertex v;
	std::vector<Vertex> vertexList;
	vertexList.reserve(6);
	v.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	vertexList.push_back(v); 
	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	vertexList.push_back(v);

	Model* model = new Model();
	model->AddMesh(new Mesh(vertexList));
	shape = new GameObject(model);

	return true;
}

void GameScene::Update(const float deltaTime_)
{
	std::cout << deltaTime_ << std::endl;
}

void GameScene::Render()
{
	shape->Render();
}
