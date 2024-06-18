#include "Command.h"

Command::Command() {
	usersRepository = UsersRepository::getInstance();
	tasksRepository = TasksRepository::getInstance();
}

void Command::regist(const MyString& username, const MyString& password) {
	if (usersRepository->getLoggedUserConst()) {
		std::cout << "User is logged! Please, log out to register new user!" << std::endl;
		return;
	}

	if (usersRepository->find(username) != -1) {
		std::cout << "Username already exsits!" << std::endl;
		std::cout << std::endl;
		return;
	}

	const User* user = new User(username, password);

	if (user) {
		usersRepository->addUser(*user);
		std::cout << "Registered successfully!" << std::endl;
		delete user;
	}
}

void Command::login(const MyString& username, const MyString& password) {
	if (usersRepository->getLoggedUserConst())
	{
		std::cout << "User is already logged!" << std::endl;
		std::cout << std::endl;
		return;
	}
	usersRepository->logInfo(username, password);
}

void Command::addTask(const MyString& name, const std::tm& dueDate, const MyString& desc) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user!" << std::endl;
		return;
	}

	if (tasksRepository->find(name)) {
		std::cout << "Task already exsits!" << std::endl;
		std::cout << std::endl;
		return;
	}
	
	const Task* task = new Task(name, dueDate, desc);

	if (task) {
		tasksRepository->addTask(*task);
		std::cout << "Task added successfully!" << std::endl;
		delete task;
	}
}

void Command::updateTaskName(unsigned id, const MyString& name) { //demo
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user to change the task!" << std::endl;
		return;
	}

	Task* task = tasksRepository->find(name);

	std::cout << "Enter new task name: " << std::endl;
	char buff[1024];
	std::cin.ignore();
	std::cin.getline(buff, 1024);
	MyString newName = buff;

	task->setName(newName);

	std::cout << "Task with ID " << task->getId() << " has new name:" << task->getName();
	std::cout << std::endl;
}

void Command::logout() {
	if(usersRepository->getLoggedUserConst()) {
		usersRepository->logOutUser();
		std::cout << "Logged out! Goodbye!" << std::endl;
		std::cout << std::endl;
	}
}

void Command::writeToFile() const
{
	std::ofstream ofs("TaskManager.dat", std::ios::out | std::ios::binary);
	if (!ofs.is_open())
		throw "Error";

	const MyVector<User>& users = usersRepository->getUsers();
	unsigned countOfUsers = users.size();
	ofs.write((const char*)&countOfUsers, sizeof(unsigned));
	for (int i = 0; i < countOfUsers; i++)
		users[i].writeToFile(ofs);
	/*size_t countOfTasks = _tasks.size();
	ofs.write((const char*)&countOfTasks, sizeof(size_t));*/
	/*for (int i = 0; i < countOfTasks; i++)
		_tasks[i].writeToFile(ofs);*/

	ofs.clear();
	ofs.close();
}
void Command::readFromFile()
{
	std::ifstream ifs("TaskManager.dat", std::ios::in | std::ios::binary);
	if (!ifs.is_open())
		throw "Error";

	unsigned countOfUsers = 0;
	ifs.read((char*)&countOfUsers, sizeof(unsigned));
	for (int i = 0; i < countOfUsers; i++) {
		User read;
		read.readFromFiLe(ifs);
		_users.push_back(read);
	}
	/*size_t countOfTasks;
	ifs.read((char*)&countOfTasks, sizeof(size_t));*/
	//for (int i = 0; i < countOfTasks; i++)
	//{
	//	Task read;
	//	read.readFromFiLe(ifs);
	//	_tasks.push_back(read);
	//}

	ifs.clear();
	ifs.close();
}
Command::~Command()
{
	writeToFile();
}