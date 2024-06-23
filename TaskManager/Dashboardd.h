#pragma once
#include "User.h"
#include "Task.h"

#pragma warning(disable : 4430)

class Dashboard {
public:
	Dashboard() = default;
	Dashboard(unsigned indexOfUser);

	void addTask(const Task& task);
	void removeTask(unsigned id);
	void updateDashboard(const MyVector<Task>& allTask, const std::tm& currentDate);

	void writeToFile(std::ofstream& ofs) const;
	void readFromFile(std::ifstream& ifs);

private:
	MyVector<Task> _tasks;
	unsigned _indexOfUser;
};

