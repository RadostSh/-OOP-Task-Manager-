#pragma once
#include <fstream>
#include "User.h"
#include "Task.h"

class Command {
public:
	Command() = default;

	void regist(const MyString& username, const MyString& password);

	void writeToFile() const;
	void readFromFile();

	~Command();
private:
	MyVector<User> _users;
	MyVector<Task> _tasks;

};