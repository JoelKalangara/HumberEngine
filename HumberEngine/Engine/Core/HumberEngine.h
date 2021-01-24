#ifndef HUMBERENGINE_
#define HUMBERENGINE_

#include"Window.h"
#include<memory>

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
	bool GetIsRunning();
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
};
#endif // !HUMBERENGINE_



