#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "Task.h"

class User {
public:
	User() = default;
	User(const MyString& username, const MyString& pass);

	const MyString& getUsername() const;
	unsigned getUserID() const;
	const MyString& getPassword() const;
	void setUsername(const MyString& username);
	void setPassword(const MyString& password);

	bool matchPassword(const MyString& password) const;

	int findTaskIndex(int id);
	Task* find(int id);
	Task* find(const MyString& name);

	void addTask(const Task& task);
	void startTask(unsigned id);
	void deleteTask(unsigned id);
	void finishTask(unsigned id);
	const MyVector<Task>& getTask() const;
	MyVector<Task>& getTask();

	void writeToFile(std::ofstream& ofs) const;
	void readFromFile(std::ifstream& ifs);

private:
	MyString _username = "Unknown";
	MyString _password = "N/A";
	unsigned _userID = 0;
	static unsigned idInSystem;

	MyVector<Task> _tasks;
};