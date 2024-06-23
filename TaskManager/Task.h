#pragma once
#include <ctime>
#include <iomanip>
#include <sstream>
#include "User.h"
#include "Status.h"


class Task {
public:
	Task() = default;
	Task(const MyString& name, const std::tm& due_data, const MyString& description, unsigned id);
	
	int getId() const;
	const MyString& getName() const;
	const std::tm& getDueDate() const;
	Status getStatus() const;
	const MyString& getDescription() const;

	void setNewStatus(Status status);
	void setName(const MyString& name);
	void setDescription(const MyString& desc);
	bool operator==(const Task& other) const;

	const MyString& getStatusStr() const;

private:
	int _id;
	MyString _name;
	std::tm _due_data;
	Status _status;
	MyString _description;
};