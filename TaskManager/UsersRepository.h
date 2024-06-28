#pragma once
#include "User.h"
#include "Task.h"
#include "Dashboardd.h"

class UsersRepository {
public: 
	UsersRepository() = default;
	static UsersRepository* getInstance();
	static void freeInstance();

	void addUser(const User& user);
	User* find(int userID);
	int find(const MyString& username) const;
	User* getUser(const MyString& username);
	void logInfo(const MyString& username, const MyString& password);
	const User* getLoggedUserConst() const; //not change user data
	User* getLoggedUser(); // change user data
	void logOutUser();
	const MyVector<User> getUsers() const;

	int findTaskIndex(int id);
	Task* findTask(int id);
	Task* findTask(const MyString& name);

	void addTask(const Task& task);
	void startTask(unsigned id);
	void deleteTask(unsigned id);
	void finishTask(unsigned id);

private:
	MyVector<User> _users;
	int loggedUser = -1;
	static UsersRepository* instance;
};