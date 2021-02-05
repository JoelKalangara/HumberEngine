#ifndef HUMBERENGINE_
#define HUMBERENGINE_

#include"Window.h"
#include<memory>
#include"Timer.h"
#include"Debug.h"
#include"GameInterface.h"
#include "Scene.h"

class HumberEngine
{
public:
	HumberEngine(const HumberEngine&)=delete;
	HumberEngine(HumberEngine&&)=delete;
	HumberEngine& operator =(const HumberEngine&) = delete;
	HumberEngine& operator =(HumberEngine&&) = delete;
	static HumberEngine* GetInstance();

	bool OnCreate(std::string name_, int width_, int height_);
	void Run();
	void Exit();

	bool GetIsRunning() const;
	int GetCurrentScene() const;

	void SetGameInterface(GameInterface* gameInterface_);
	void SetCurrentScene(int sceneNum_);

private:
	HumberEngine();
	~HumberEngine();
	void Update(const float deltaTime_);
	void Render();
	void OnDestroy();

	static std::unique_ptr<HumberEngine> engineInstance;
	friend std::default_delete<HumberEngine>;

	Window* window;
	bool isRunning;

	Timer* timer;
	unsigned int fps;

	GameInterface* gameInterface;

	int currentSceneNum;
};
#endif // !HUMBERENGINE_



