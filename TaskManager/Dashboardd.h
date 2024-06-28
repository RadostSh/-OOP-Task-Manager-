#pragma once
#include "User.h"
#include "Task.h"
#pragma warning(disable : 4430)
#pragma warning(disable : 4996)

class Dashboard {
public:
	Dashboard() = default;
	Dashboard(unsigned indexOfUser);

	void addTask(const Task& task);
	void removeTask(unsigned id);
	void updateDashboard(const MyVector<Task>& allTask, const std::tm& currentDate);
	void updateDashboardForDate(const MyVector<Task>& allTasks, const std::tm& specificDate);
	void listTasksDueToday() const;

private:
	MyVector<Task> _tasks;
	unsigned _indexOfUser;
};
