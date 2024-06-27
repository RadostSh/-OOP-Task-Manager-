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