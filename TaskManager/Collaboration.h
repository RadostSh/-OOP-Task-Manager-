#pragma once
#include "User.h"
#include "Task.h"
#include "Pair.hpp"

class Collaboration {
public:
private:
	MyVector<User> _users;
	MyVector<Pair<Task, MyString>> _tasks;
};