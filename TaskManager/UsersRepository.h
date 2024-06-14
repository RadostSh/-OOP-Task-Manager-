#pragma once
#include "User.h"

class UsersRepository {
public: 
	UsersRepository() = default;
	static UsersRepository* getInstance();
	static void freeInstance();

	void addUser(const User& user);
	User* find(int userID);
	int find(const MyString& username) const;
	void logInfo(const MyString& username, const MyString& password);
	const User* getLoggedUserConst() const; //not change user data
	User* getLoggedUser(); // change user data
	void logOutUser();

private:
	MyVector<User> _users;
	int loggedUser = -1;
	static UsersRepository* instance;
};