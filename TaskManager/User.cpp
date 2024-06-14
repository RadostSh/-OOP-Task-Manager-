#include "User.h"
#include "SerializeFunction.h"

unsigned User::idInSystem = 0;

User::User(const MyString& username, const MyString& pass) {
	setUsername(username);
	setPassword(pass);
	_userID = idInSystem++;
}

const MyString& User::getUsername() const {
	return _username;
}

unsigned User::getUserID() const {
	return _userID;
}

void User::setUsername(const MyString& username) {
	if (username.getSize() < 3)
	{
		throw std::invalid_argument("Username must be at least 3 symbols!");
	}

	_username = username;
}

void User::setPassword(const MyString& password) {
	if (password.getSize() < 8)
	{
		throw std::invalid_argument("Password must be at least 8 symbols!");
	}

	_password = password;
}

bool User::matchPassword(const MyString& password) const {
	return password == _password;
}

void User::writeToFile(std::ofstream& ofs) const {
	writeStringToFile(ofs, _username);
	writeStringToFile(ofs, _password);
	//ofs.write((const char*)&_userID, sizeof(unsigned));
	//
}

void User::readFromFiLe(std::ifstream& ifs) {
	_username = readStringFromFile(ifs);
	_password = readStringFromFile(ifs);
	//ifs.read((char*)&_userID, sizeof(unsigned));
	//
}