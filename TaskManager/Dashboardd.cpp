#include "Dashboardd.h"
#include "HelperFunctions.h"

Dashboard::Dashboard(unsigned indexOfUser) {
    _indexOfUser = indexOfUser;
}

void Dashboard::addTask(const Task& task) {
    _tasks.push_back(task);
}

void Dashboard::removeTask(unsigned id) {
    for (size_t i = 0; i < _tasks.size(); ++i) {
        if (_tasks[i].getId() == id) {
            _tasks.erase(i);
            break;
        }
    }
}

void Dashboard::updateDashboard(const MyVector<Task>& allTasks, const std::tm& currentDate) {
    _tasks.clear();
    unsigned tasksCount = allTasks.size();

    // Converts a std::tm to std::time_t
    std::time_t currentTime = toTimeT(currentDate);

    for (size_t i = 0; i < tasksCount; i++) {
        const Task& task = allTasks[i];
        std::time_t taskDueTime = toTimeT(task.getDueDate());

        // Compare the due date of the task with the current date
        if (taskDueTime <= currentTime && task.getStatus() != Status::OVERDUE) {
            _tasks.push_back(task);
        }
    }
}

void Dashboard::updateDashboardForDate(const MyVector<Task>& allTasks, const std::tm& specificDate) {
    _tasks.clear();
    for (size_t i = 0; i < allTasks.size(); i++) {
        if (isSameDate(allTasks[i].getDueDate(), specificDate)) {
            _tasks.push_back(allTasks[i]);
        }
    }
}

void Dashboard::listTasksDueToday() const {

    std::time_t t = std::time(nullptr);
    std::tm currentDate = *std::localtime(&t);

    for (size_t i = 0; i < _tasks.size(); ++i) {
        if (isToday(_tasks[i].getDueDate())) {
            std::cout << "Task Name: " << _tasks[i].getName() << std::endl;
            std::cout << "Task ID: " << _tasks[i].getId() << std::endl;
            std::cout << "Task Due Date: " << std::put_time(&_tasks[i].getDueDate(), "%Y-%m-%d");
            std::cout << "Task Description: " << _tasks[i].getDescription() << std::endl;
            std::cout << std::endl;
        }
    }
}
