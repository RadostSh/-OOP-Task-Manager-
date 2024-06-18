#pragma once
#include <fstream>
#include "User.h"
#include "Task.h"
#include "UsersRepository.h"
#include "TasksRepository.h"

class Command {
public:
	Command();

	void regist(const MyString& username, const MyString& password);
	void login(const MyString& username, const MyString& password);
	void addTask(const MyString& name, const std::tm& dueDate, const MyString& desc);
	void updateTaskName(unsigned id, const MyString& name);

	void logout();

	void writeToFile() const;
	void readFromFile();

	~Command();
protected:
	UsersRepository* usersRepository;
	TasksRepository* tasksRepository;
private:
	MyVector<User> _users;
	MyVector<Task> _tasks;
};