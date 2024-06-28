#include "User.h"
#include "SerializeFunction.h"

unsigned User::idInSystem = 0;

User::User(const MyString& username, const MyString& pass) {
	setUsername(username);
	setPassword(pass);
	_userID = idInSystem++;
}

const MyString& User::getUsername() const {
	return _username;
}

unsigned User::getUserID() const {
	return _userID;
}

const MyString& User::getPassword() const {
	return _password;
}

void User::setUsername(const MyString& username) {
	if (username.getSize() < 3)
	{
		throw std::invalid_argument("Username must be at least 3 symbols!");
	}

	_username = username;
}

void User::setPassword(const MyString& password) {
	if (password.getSize() < 8)
	{
		throw std::invalid_argument("Password must be at least 8 symbols!");
	}

	_password = password;
}

bool User::matchPassword(const MyString& password) const {
	return password == _password;
}

int User::findTaskIndex(int id) {
	unsigned tasksCount = _tasks.size();

	for (size_t index = 0; index < tasksCount; index++) {
		if (_tasks[index].getId() == id) {
			return index;
		}
	}
	return -1;
}

Task* User::find(int id) {
	int taskIndex = findTaskIndex(id);
	return taskIndex == -1 ? nullptr : &_tasks[taskIndex];
}

Task* User::find(const MyString& name) {
	unsigned tasksCount = _tasks.size();

	for (size_t i = 0; i < tasksCount; i++) {
		if (_tasks[i].getName() == name) {
			return &_tasks[i];
		}
	}
	return nullptr;
}

void User::addTask(const Task& task) {
	_tasks.push_back(task);
}

void User::startTask(unsigned id) {
	int index = findTaskIndex(id);
	if (index != -1) {
		_tasks[index].setNewStatus(Status::IN_PROCESS);
	}
}

void User::deleteTask(unsigned id) {

	for (size_t i = 0; i < _tasks.size(); ++i) {
		if (_tasks[i].getId() == id) {
			_tasks.erase(i);
			break;
		}
	}
}

void User::finishTask(unsigned id) {
	int index = findTaskIndex(id);
	if (index != -1) {
		_tasks[index].setNewStatus(Status::DONE);
	}
}

const MyVector<Task>& User::getTask() const {
	return _tasks;
}

MyVector<Task>& User::getTask() {
	return _tasks;
}

void User::writeToFile(std::ofstream& ofs) const {
	writeStringToFile(ofs, _username);
	writeStringToFile(ofs, _password);
	ofs.write((const char*)&_userID, sizeof(unsigned));
	ofs.write((const char*)&idInSystem, sizeof(unsigned));

	const MyVector<Task>& tasks = getTask();
	size_t countOfTasks = tasks.size();
	ofs.write((const char*)&countOfTasks, sizeof(size_t));
	for (int i = 0; i < countOfTasks; i++) {
		tasks[i].writeToFile(ofs);
	}
}

void User::readFromFile(std::ifstream& ifs) {
	_username = readStringFromFile(ifs);
	_password = readStringFromFile(ifs);
	ifs.read((char*)&_userID, sizeof(unsigned));
	ifs.read((char*)&idInSystem, sizeof(unsigned));

	size_t countOfTasks = 0;
	ifs.read((char*)&countOfTasks, sizeof(size_t));
	for (int i = 0; i < countOfTasks; i++) {
		Task read;
		read.readFromFile(ifs);
		addTask(read);
	}
}