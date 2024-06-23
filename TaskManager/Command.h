#pragma once
#include <fstream>
#include "User.h"
#include "Task.h"
#include "Dashboardd.h"
#include "UsersRepository.h"
#include "TasksRepository.h"
#include "CollaborationRepository.h"
#pragma warning(disable : 4996)

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
	void getTask(const MyString& name);
	void getTask(unsigned id);

	void listCompletedTasks();
	void listDashboard();
	void finishTask(unsigned id);

	void addCollaboration(const MyString& name);
	void deleteCollaboration(const MyString& name);
	void listCollaborations();
	void addUser(const MyString& collabName, const MyString& username);
	void assignTask(const MyString& collabName, const MyString& username, const MyString& name, const std::tm& dueDate, const MyString& desc);
	void listTasks(const MyString& collabName);

	void logout();

	void writeToFile() const;
	void readFromFile();

	~Command();
protected:
	UsersRepository* usersRepository;
	TasksRepository* tasksRepository;
	CollaborationsRepository* collaborationsRepository;
private:
	MyVector<User> _users;
	MyVector<Task> _tasks;
};