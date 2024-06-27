#pragma once
#include "User.h"
#include "Task.h"
#include "SerializeFunction.h"

class CollaborationTask : Task {
public:
	CollaborationTask() = default;
	CollaborationTask(const MyString& name, const std::tm& dueDate, const MyString& description, unsigned id);

	const Task& getTask() const;
	const MyString& getAssignee() const;
	void setAssignee(const MyString& assignee);
	const MyString& getName() const;

	void writeToFile(std::ofstream& ofs) const;
	void readFromFile(std::ifstream& ifs);

private:
	MyString _assignee;
};