#pragma once
#include "Task.h"

class TasksRepository {
public:
	TasksRepository() = default;
	static TasksRepository* getInstance();
	static void freeInstance();

	int findTaskIndex(int id);
	Task* find(int id);
	Task* find(const MyString& name);
	
	void addTask(const Task& task);
	void startTask(unsigned id);
	const MyVector<Task> getTask() const;
private:
	MyVector<Task> _tasks;
	static TasksRepository* instance;
};