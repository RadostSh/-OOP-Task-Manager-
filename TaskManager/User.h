#pragma once
#include "MyString.h"
#include "MyVector.hpp"

class User {
public:
	User() = default;
	User(const MyString& username, const MyString& pass);

	const MyString& getUsername() const;
	unsigned getUserID() const;
	void setUsername(const MyString& username);
	void setPassword(const MyString& password);

	//void printUserInfo() const;

	bool matchPassword(const MyString& password) const;

	void writeToFile(std::ofstream& ofs) const;
	void readFromFiLe(std::ifstream& ifs);

private:
	MyString _username = "Unknown";
	MyString _password = "N/A";
	unsigned _userID = 0;
	static unsigned idInSystem;
};