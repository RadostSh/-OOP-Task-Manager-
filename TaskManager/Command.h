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
	void updateTaskName(const MyString& name);
	void updateTaskName(unsigned id);
	void startTask(unsigned id);
	void updateTaskDescription(const MyString& name);
	void updateTaskDescription(unsigned id);
	void addTaskToDashboard(unsigned id);
	void removeTaskFromDashboard(unsigned id);
	void deleteTask(unsigned id);
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