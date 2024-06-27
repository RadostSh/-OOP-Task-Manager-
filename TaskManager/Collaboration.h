#pragma once
#include "User.h"
#include "Task.h"
#include "CollaborationTask.h"
#include "SerializeFunction.h"

class Collaboration {
public:
	Collaboration() = default;
	Collaboration(const MyString& name, const MyString& creator, int id);

	const MyString& getName() const;
	const MyString& getCreator() const;
	int getId() const;
	MyVector<CollaborationTask>& getCollaborationTasks();

	void addUser(const User& user);
	bool isUserInWorkGroup(const MyString& username) const;
	void addTask(const CollaborationTask& newTask);

	void writeToFile(std::ofstream& ofs) const;
	void readFromFile(std::ifstream& ifs);

private:
	MyString _name;
	MyString _creator;
	int _id;
	MyVector<User> _workGroup;
	MyVector<CollaborationTask> _collaborationTask;
};