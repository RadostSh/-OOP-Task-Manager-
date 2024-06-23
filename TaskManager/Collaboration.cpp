#include "Collaboration.h"

Collaboration::Collaboration(const MyString& name, const MyString& creator, int id) {
	_name = name;
	_creator = creator;
	_id = id;
}

const MyString& Collaboration::getName() const {
	return _name;
}

const MyString& Collaboration::getCreator() const {
	return _creator;
}

int Collaboration::getId() const {
	return _id;
}

MyVector<CollaborationTask>& Collaboration::getCollaborationTasks() {
	return _collaborationTask;
}

void Collaboration::addUser(const User& user) {
	_workGroup.push_back(user);
}

bool Collaboration::isUserInWorkGroup(const MyString& username) const {
	for (size_t i = 0; i < _workGroup.size(); i++) {
		if (_workGroup[i].getUsername() == username) {
			return true;
		}
	}
	return false;
}

void Collaboration::addTask(const CollaborationTask* newTask) {
	_collaborationTask.push_back(*newTask);
}

