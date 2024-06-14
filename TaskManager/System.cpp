#include "System.h"
#include "Command.h"
#include "SerializeFunction.h"
#include "HelperFunctions.h"

void run() {
	Command command;
	command.readFromFile();
	MyString commandText;

	std::cout << "Welcome to Task Manager!\nChoose an option: signup or login" << std::endl;

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
		else if (commandText == "login") {
			MyString username, password;
			std::cout << "Username: ";
			std::cin >> username;
			std::cout << "Password: ";
			std::cin >> password;

			command.login(username, password);
			std::cout << std::endl;
		}
		else if (commandText == "logout") {
			command.logout();
		}
		else if (commandText == "exit") {
			break;
		}
		else {
			throw std::invalid_argument("Invalid command");
		}
	}	
}