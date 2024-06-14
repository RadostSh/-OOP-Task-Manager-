#include "Command.h"

Command::Command() {
	usersRepository = UsersRepository::getInstance();
}

void Command::regist(const MyString& username, const MyString& password) {
	if (usersRepository->getLoggedUserConst()) {
		std::cout << "User is logged! Please, log out to register new user!" << std::endl;
		return;
	}

	if (usersRepository->find(username) != -1) {
		std::cout << "Username already exsits!" << std::endl;
		return;
	}

	const User* user = new User(username, password);

	if (user) {
		usersRepository->addUser(*user);
		std::cout << "Registered successfully!" << std::endl;
		delete user;
	}
}

void Command::writeToFile() const
{
	std::ofstream ofs("TaskManager.dat", std::ios::out | std::ios::binary);
	if (!ofs.is_open())
		throw "Error";

	size_t countOfUsers = _users.size();
	ofs.write((const char*)&countOfUsers, sizeof(size_t));
	for (int i = 0; i < countOfUsers; i++)
		_users[i].writeToFile(ofs);
	/*size_t countOfTopics = _tasks.size();
	ofs.write((const char*)&countOfTopics, sizeof(size_t));
	for (int i = 0; i < countOfTopics; i++)
		_tasks[i].writeToFile(ofs);*/

	ofs.clear();
	ofs.close();
}
void Command::readFromFile()
{
	std::ifstream ifs("TaskManager.dat", std::ios::in | std::ios::binary);
	if (!ifs.is_open())
		throw "Error";

	size_t countOfUsers;
	ifs.read((char*)&countOfUsers, sizeof(size_t));
	for (int i = 0; i < countOfUsers; i++)
	{
		User read;
		read.readFromFiLe(ifs);
		_users.push_back(read);
	}
	//size_t countOfTopics;
	//ifs.read((char*)&countOfTopics, sizeof(size_t));
	//for (int i = 0; i < countOfTopics; i++)
	//{
	//	Task readT;
	//	readT.readFromFiLe(ifs);
	//	_tasks.push_back(readT);
	//}

	ifs.clear();
	ifs.close();
}
Command::~Command()
{
	writeToFile();
}