#include <iostream>
#include "System.h"

//Line 1-8 are included in all .cpp files to check for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //first line in main function

	try {
		run();
	}
	catch (std::invalid_argument& exc)
	{
		std::cout << exc.what() << std::endl;
	}
	catch (std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Invalid argument given" << std::endl;
	}
	return 0;
}

