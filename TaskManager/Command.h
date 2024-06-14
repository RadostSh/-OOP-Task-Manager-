#pragma once
#include <fstream>
#include "User.h"
#include "Task.h"
#include "UsersRepository.h"

class Command {
public:
	Command();

	void regist(const MyString& username, const MyString& password);

	void writeToFile() const;
	void readFromFile();

	~Command();
protected:
	UsersRepository* usersRepository;
private:
	MyVector<User> _users;
	MyVector<Task> _tasks;

};