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

void Collaboration::addTask(const CollaborationTask& newTask) {
	_collaborationTask.push_back(newTask);
}

void Collaboration::writeToFile(std::ofstream& ofs) const {
	writeStringToFile(ofs, _name);
	writeStringToFile(ofs, _creator);
	ofs.write((const char*)&_id, sizeof(int));

	size_t workGroupSize = _workGroup.size();
	ofs.write((const char*)&workGroupSize, sizeof(size_t));
	for (int i = 0; i < workGroupSize; i++) {
		_workGroup[i].writeToFile(ofs);
	}

	size_t taskSize = _collaborationTask.size();
	ofs.write((const char*)&taskSize, sizeof(size_t));
	for (int i = 0; i < taskSize; i++) {
		_collaborationTask[i].writeToFile(ofs);
	}
}

void Collaboration::readFromFile(std::ifstream& ifs) {

	_name = readStringFromFile(ifs);
	_creator = readStringFromFile(ifs);


	ifs.read((char*)&_id, sizeof(int));


	size_t workGroupSize;
	ifs.read((char*)&workGroupSize, sizeof(size_t));
	for (size_t i = 0; i < workGroupSize; ++i) {
		_workGroup[i].readFromFile(ifs);
	}

	size_t taskSize;
	ifs.read((char*)&taskSize, sizeof(size_t));
	for (size_t i = 0; i < taskSize; ++i) {
		_collaborationTask[i].readFromFile(ifs);
	}
}