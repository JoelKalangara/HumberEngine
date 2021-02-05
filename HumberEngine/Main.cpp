#include"Engine/Core/HumberEngine.h"
#include"Game/Game1.h"

int main(int argc, char* argv[]) 
{
	HumberEngine::GetInstance()->SetGameInterface(new Game1());

	if (!HumberEngine::GetInstance()->OnCreate("HumberEngine",800,600))
	{
		//std::cout << "Engine failed to initialize" << std::endl;
		Debug::FatalError("Engine failed to initialize", "Main.cpp", __LINE__);
		return 0;
	}
	HumberEngine::GetInstance()->Run();
	return 0;
}