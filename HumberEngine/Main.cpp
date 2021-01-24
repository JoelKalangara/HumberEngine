#include"Engine/Core/HumberEngine.h"

int main(int argc, char* argv[]) 
{
	if (!HumberEngine::GetInstance()->OnCreate("HumberEngine",800,600))
	{
		std::cout << "Engine failed to initialize" << std::endl;
		return 0;
	}
	HumberEngine::GetInstance()->Run();
	return 0;
}