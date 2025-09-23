#include <iostream>

#include "Utils/ConsoleControl.h"

#include <functional>

void TestLambasMolonas(std::function<void()> funcionMolona)
{
	std::cout << "Voy a ejecutar una funciion aaaaaaaaaaa" << std::endl;
	
	funcionMolona();
	
	std::cout << "ya e ejecutado la function" << std::endl;
}

int main()
{
	std::function<void()> funcionKHaceCosasPeroS1Variable = []() {
		std::cout << "Esto no se como pero funca" << std::endl;
		};

	TestLambasMolonas(funcionKHaceCosasPeroS1Variable);
}

