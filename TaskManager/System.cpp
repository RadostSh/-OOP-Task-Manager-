#include "System.h"
#include "Command.h"
#include "SerializeFunction.h"
#include "HelperFunctions.h"

void run() {
	Command command;
	command.readFromFile();
	MyString commandText;

	std::cout << "Welcome to Task Manager!\n Choose an option: signup or login" << std::endl;

	while (true) {

		std::cin >> commandText;

		if (commandText == "signup") {
			MyString username, password;
			std::cout << "Username: ";
			std::cin >> username;
			std::cout << "Password: ";
			std::cin >> password;

			command.regist(username, password);
			std::cout << std::endl;
		}
	}
	
	

}