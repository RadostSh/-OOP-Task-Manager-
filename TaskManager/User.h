#pragma once
#include "MyString.h"
#include "MyVector.hpp"

class User {
public:
	User() = default;
	User(const MyString& us, const MyString& pass);

	const MyString& getUsername() const;
	unsigned getId() const;
	void setUsername(const MyString& username);
	void setPassword(const MyString& password);

	bool isPass(const MyString& pass) const;
	bool isName(const MyString& name) const;
	void printUserInfo() const;

	void writeToFile(std::ofstream& ofs) const;
	void readFromFiLe(std::ifstream& ifs);
private:
	MyString _username = "Unknown";
	MyString _password = "N/A";
	unsigned _userID = 0;

};