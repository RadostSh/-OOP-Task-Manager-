#include "TasksRepository.h"

TasksRepository* TasksRepository::instance = nullptr;

TasksRepository* TasksRepository::getInstance() {
	if (!instance) {
		instance = new TasksRepository();
	}
	return instance;
}

void TasksRepository::freeInstance() {
	delete instance;
	instance = nullptr;
}

int TasksRepository::findTaskIndex(int id) {
	unsigned tasksCount = _tasks.size();

	for (size_t index = 0; index < tasksCount; index++) {
		if (_tasks[index].getId() == id) {
			return index;
		}
	}
	return -1;
}

Task* TasksRepository::find(int id) {
	int taskIndex = findTaskIndex(id);
	return taskIndex == -1 ? nullptr : &_tasks[taskIndex];
}

Task* TasksRepository::find(const MyString& name) {
	unsigned tasksCount = _tasks.size();

	for (size_t i = 0; i < tasksCount; i++) {
		if (_tasks[i].getName() == name) {
			return &_tasks[i];
		}
	}
	return nullptr;
}

void TasksRepository::addTask(const Task& task) {
	_tasks.push_back(task);
}

const MyVector<Task>& TasksRepository::getTask() const {
	return _tasks;
}

void TasksRepository::startTask(unsigned id) {
	int index = findTaskIndex(id);
	if (index != -1) {
		_tasks[index].setNewStatus(Status::IN_PROCESS);
	}
}