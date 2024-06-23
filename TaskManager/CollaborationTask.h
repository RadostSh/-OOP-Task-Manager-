#pragma once
#include "User.h"
#include "Task.h"

class CollaborationTask : Task {
public:
	CollaborationTask() = default;
	CollaborationTask(const MyString& name, const std::tm& dueDate, const MyString& description, unsigned id);

	const Task& getTask() const;
	const MyString& getAssignee() const;
	void setAssignee(const MyString& assignee);

private:
	MyString _assignee;
};