#include "UsersRepository.h"

UsersRepository* UsersRepository::instance = nullptr;

UsersRepository* UsersRepository::getInstance() {
	if (!instance) {
		instance = new UsersRepository();
	}
	return instance;
}

void UsersRepository::freeInstance() {
	delete instance;
	instance = nullptr;
}

void UsersRepository::addUser(const User& user) {
	_users.push_back(user);
}

User* UsersRepository::find(int userID) {
	if (userID == -1) {
		return nullptr;
	}

	unsigned usersCount = _users.size();

	for (size_t i = 0; i < usersCount; i++) {
		if (_users[i].getUserID() == userID) {
			return &_users[i];
		}
	}
	return nullptr;
}

int UsersRepository::find(const MyString& username) const {

	unsigned usersCount = _users.size();

	for (size_t i = 0; i < usersCount; i++) {
		if (_users[i].getUsername() == username) {
			return i;
		}
	}
	return -1;
}

void UsersRepository::logInfo(const MyString& username, const MyString& password) {
	int userIndex = find(username);

	if (userIndex == -1) {
		std::cout << "Sorry, username is not found! Try again!";
	}

	if (_users[userIndex].matchPassword(password)) {
		loggedUser = userIndex;
		std::cout << "Registered successfully!";
	}

	std::cout << "Wrong password! Try again!";
}

const User* UsersRepository::getLoggedUserConst() const {
	return loggedUser == -1 ? nullptr : &_users[loggedUser];
}

User* UsersRepository::getLoggedUser() {
	return loggedUser == -1 ? nullptr : &_users[loggedUser];
}

void UsersRepository::logOutUser() {
	loggedUser = -1;
}