#pragma once
#include <ctime>
#include <iomanip>
#include "User.h"
#include "Status.h"


class Task {
public:
	Task() = default;
private:
	unsigned _id;
	MyString _name;
	//due_data;
	Status status;
	MyString _description;
};