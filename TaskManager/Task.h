#pragma once
#include <ctime>
#include <iomanip>
#include <sstream>
#include "MyString.h"
#include "MyVector.hpp"
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
	bool isCompleted() const;

	void setNewStatus(Status status);
	void setName(const MyString& name);
	void setDescription(const MyString& desc);
	bool operator==(const Task& other) const;

	MyString getStatusStr() const;

	void writeToFile(std::ofstream& ofs) const;
	void readFromFile(std::ifstream& ifs);

	friend void mySwap(Task& first, Task& second) noexcept;

private:
	int _id;
	MyString _name;
	std::tm _due_data;
	Status _status;
	MyString _description;
};