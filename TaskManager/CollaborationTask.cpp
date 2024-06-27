#include "CollaborationTask.h"

CollaborationTask::CollaborationTask(const MyString& name, const std::tm& dueDate, const MyString& description, unsigned id)
	: Task(name, dueDate, description, id), _assignee("") {}

const Task& CollaborationTask::getTask() const {
	return *this;
}

const MyString& CollaborationTask::getAssignee() const {
	return _assignee;
}

void CollaborationTask::setAssignee(const MyString& assignee) {
	_assignee = assignee;
}

const MyString& CollaborationTask::getName() const {
	return Task::getName();
}

void CollaborationTask::writeToFile(std::ofstream& ofs) const {
	Task::writeToFile(ofs);
	writeStringToFile(ofs, _assignee);
}

void CollaborationTask::readFromFile(std::ifstream& ifs) {
	Task::readFromFile(ifs);
	_assignee = readStringFromFile(ifs);
}