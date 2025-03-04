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
		else if (commandText == "add-task") {
			char buff[1024];
			std::cin.ignore();

			std::cout << "Enter task name: ";
			std::cin.getline(buff, 1024);
			MyString name = buff;

			std::cout << "Enter due date (YYYY-MM-DD): ";
			std::cin.getline(buff, 1024);
			MyString dateStr = buff;
			std::tm dueDate = {};
			std::istringstream ss(dateStr.c_str());
			ss >> std::get_time(&dueDate, "%Y-%m-%d");

			if (ss.fail()) {
				std::cout << "Date format is invalid! Please use YYYY-MM-DD" << std::endl;
				return;
			}

			std::cout << "Enter description: ";
			std::cin.getline(buff, 1024);
			MyString desc = buff;

			command.addTask(name, dueDate, desc);
			std::cout << std::endl;
		}
		else if (commandText == "update-task-name") {
			std::cout << "Enter task ID or task name: ";
			char buff[1024];
			std::cin.ignore();
			std::cin.getline(buff, 1024);
			MyString input = buff;
			if (isDigit(input[0])) {
				command.updateTaskName(getNumFromStr(input));
			}
			else {
				command.updateTaskName(input);
			}
			std::cout << std::endl;
		}
		else if (commandText == "start-task") {
			std::cout << "Enter task ID: ";
			unsigned id;
			std::cin >> id;

			command.startTask(id);
			std::cout << std::endl;
		}
		else if (commandText == "update-task-description") {
			std::cout << "Enter task ID or task name: ";
			char buff[1024];
			std::cin.ignore();
			std::cin.getline(buff, 1024);
			MyString input = buff;
			if (isDigit(input[0])) {
				command.updateTaskDescription(getNumFromStr(input));
			}
			else {
				command.updateTaskDescription(input);
			}
			std::cout << std::endl;
		}
		else if (commandText == "add-task-to-dashboard") {
			std::cout << "Enter task ID: ";
			unsigned id;
			std::cin >> id;

			command.addTaskToDashboard(id);
			std::cout << std::endl;
		}
		else if (commandText == "remove-task-from-dashboard") {
			std::cout << "Enter task ID: ";
			unsigned id;
			std::cin >> id;

			command.removeTaskFromDashboard(id);
			std::cout << std::endl;
		}
		else if (commandText == "delete-task") {
			std::cout << "Enter task ID: ";
			unsigned id;
			std::cin >> id;

			command.deleteTask(id);
			std::cout << std::endl;
		}
		else if (commandText == "get-task") {
			std::cout << "Enter task ID or task name: ";
			char buff[1024];
			std::cin.ignore();
			std::cin.getline(buff, 1024);
			MyString input = buff;
			if (isDigit(input[0])) {
				command.getTask(getNumFromStr(input));
			}
			else {
				command.getTask(input);
			}
			std::cout << std::endl;
		}
		else if (commandText == "list-tasks-by-date") {
			char buff[1024];
			std::cin.ignore();
			std::cout << "Enter date (YYYY-MM-DD): ";
			std::cin.getline(buff, 1024);
			MyString dateStr = buff;
			std::tm date = {};
			std::istringstream ss(dateStr.c_str());
			ss >> std::get_time(&date, "%Y-%m-%d");

			if (ss.fail()) {
				std::cout << "Date format is invalid! Please use YYYY-MM-DD" << std::endl;
				return;
			}

			command.listTasks(date);
			std::cout << std::endl;
		}
		else if (commandText == "list-all-tasks") {
			command.listAllTasks();
			std::cout << std::endl;
		}
		else if (commandText == "list-completed-tasks") {
			command.listCompletedTasks();
			std::cout << std::endl;
		}
		else if (commandText == "list-dashboard") {
			command.listDashboard();
			std::cout << std::endl;
		}
		else if (commandText == "finish-task") {
			std::cout << "Enter task ID: ";
			unsigned id;
			std::cin >> id;

			command.finishTask(id);
			std::cout << std::endl;
		}
		else if (commandText == "add-collaboration") {
			MyString name;
			std::cout << "Name: ";
			std::cin >> name;

			command.addCollaboration(name);
			std::cout << std::endl;
		}
		else if (commandText == "delete-collaboration") {
			MyString name;
			std::cout << "Name: ";
			std::cin >> name;

			command.deleteCollaboration(name);
			std::cout << std::endl;
		}
		else if (commandText == "list-collaborations") {
			command.listCollaborations();
			std::cout << std::endl;
		}
		else if (commandText == "add-user") {
			MyString collabName;
			std::cout << "Collaboration name: ";
			std::cin >> collabName;

			MyString username;
			std::cout << "Username: ";
			std::cin >> username;

			command.addUser(collabName, username);
			std::cout << std::endl;
		}
		else if (commandText == "assign-task") {

			char buff[1024];
			std::cin.ignore();

			std::cout << "Enter collaboration name: ";
			std::cin.getline(buff, 1024);
			MyString collabName = buff;

			std::cout << "Enter username: ";
			std::cin.getline(buff, 1024);
			MyString username = buff;

			std::cout << "Enter task name: ";
			std::cin.getline(buff, 1024);
			MyString name = buff;

			std::cout << "Enter due date (YYYY-MM-DD): ";
			std::cin.getline(buff, 1024);
			MyString dateStr = buff;
			std::tm dueDate = {};
			std::istringstream ss(dateStr.c_str());
			ss >> std::get_time(&dueDate, "%Y-%m-%d");

			if (ss.fail()) {
				std::cout << "Date format is invalid! Please use YYYY-MM-DD" << std::endl;
				return;
			}

			std::cout << "Enter description: ";
			std::cin.getline(buff, 1024);
			MyString desc = buff;

			command.assignTask(collabName, username, name, dueDate, desc);
			std::cout << std::endl;

		}
		else if (commandText == "list-tasks-by-collabName") {
			MyString collabName;
			std::cout << "Collaboration name: ";
			std::cin >> collabName;

			command.listTasks(collabName);
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