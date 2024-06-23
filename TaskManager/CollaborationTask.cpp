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