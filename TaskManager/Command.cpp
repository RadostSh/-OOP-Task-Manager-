#include "Command.h"

Command::Command() {
	usersRepository = UsersRepository::getInstance();
	tasksRepository = TasksRepository::getInstance();
	collaborationsRepository = CollaborationsRepository::getInstance();
}

void Command::regist(const MyString& username, const MyString& password) {
	if (usersRepository->getLoggedUserConst()) {
		std::cout << "User is logged! Please, log out to register new user!" << std::endl;
		return;
	}

	if (usersRepository->find(username) != -1) {
		std::cout << "Username already exsits!" << std::endl;
		std::cout << std::endl;
		return;
	}

	const User* user = new User(username, password);

	if (user) {
		usersRepository->addUser(*user);
		std::cout << "Registered successfully!" << std::endl;
		delete user;
	}
}

void Command::login(const MyString& username, const MyString& password) {
	if (usersRepository->getLoggedUserConst())
	{
		std::cout << "User is already logged!" << std::endl;
		std::cout << std::endl;
		return;
	}
	usersRepository->logInfo(username, password);
}

void Command::addTask(const MyString& name, const std::tm& dueDate, const MyString& desc) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user!" << std::endl;
		return;
	}

	if (tasksRepository->find(name)) {
		std::cout << "Task already exsits!" << std::endl;
		std::cout << std::endl;
		return;
	}
	static bool isRandInitialized = false;
	if (!isRandInitialized) {
		srand(time(NULL));
		isRandInitialized = true;
	}
	int id = rand();

	Task task(name, dueDate, desc, id);
	tasksRepository->addTask(task);
	std::cout << "Task added successfully!" << std::endl;
}

void Command::updateTaskName(const MyString& name) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user to change the task!" << std::endl;
		return;
	}

	Task* task = tasksRepository->find(name);

	std::cout << "Enter new task name: " << std::endl;
	char buff[1024];
	std::cin.ignore();
	std::cin.getline(buff, 1024);
	MyString newName = buff;

	task->setName(newName);

	std::cout << "Task with ID " << task->getId() << " has new name:" << task->getName();
	std::cout << std::endl;
}

void Command::updateTaskName(unsigned id) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user to change the task!" << std::endl;
		return;
	}

	Task* task = tasksRepository->find(id);

	std::cout << "Enter new task name: " << std::endl;
	char buff[1024];
	std::cin.ignore();
	std::cin.getline(buff, 1024);
	MyString newName = buff;

	task->setName(newName);

	std::cout << "Task with ID " << task->getId() << " has new name:" << task->getName();
	std::cout << std::endl;
}

void Command::startTask(unsigned id) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user!" << std::endl;
		return;
	}

	tasksRepository->startTask(id);
	std::cout << "Task started successfully!" << std::endl;
}

void Command::updateTaskDescription(const MyString& name) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user!" << std::endl;
		return;
	}

	Task* task = tasksRepository->find(name);

	std::cout << "Enter new task description: " << std::endl;
	char buff[1024];
	std::cin.ignore();
	std::cin.getline(buff, 1024);
	MyString newDesc = buff;

	task->setDescription(newDesc);

	std::cout << "Task description is change successfully!" << std::endl;
	std::cout << std::endl;
}

void Command::updateTaskDescription(unsigned id) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user!" << std::endl;
		return;
	}

	Task* task = tasksRepository->find(id);

	std::cout << "Enter new task description: " << std::endl;
	char buff[1024];
	std::cin.ignore();
	std::cin.getline(buff, 1024);
	MyString newDesc = buff;

	task->setDescription(newDesc);

	std::cout << "Task description is change successfully!" << std::endl;
	std::cout << std::endl;
}

void Command::addTaskToDashboard(unsigned id) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user!" << std::endl;
		return;
	}

	Task* task = tasksRepository->find(id);

	if (!task) {
		std::cout << "Task not found!" << std::endl;
		return;
	}

	if (task->getStatus() == Status::OVERDUE) {
		std::cout << "Cannot add task to dashboard. Task is overdue!" << std::endl;
		return;
	}

	unsigned indexOfUser = user->getUserID();
	Dashboard dashboard(indexOfUser);
	dashboard.addTask(*task);

	std::cout << "Task added to dashboard successfully!" << std::endl;
}

void Command::removeTaskFromDashboard(unsigned id) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user!" << std::endl;
		return;
	}

	Task* task = tasksRepository->find(id);
	if (!task) {
		std::cout << "Task with ID " << id << " not found!" << std::endl;
		return;
	}

	unsigned indexOfUser = user->getUserID();
	Dashboard dashboard(indexOfUser);
	dashboard.removeTask(id);

	std::cout << "Task removed from dashboard successfully!" << std::endl;

}

void Command::deleteTask(unsigned id) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user!" << std::endl;
		return;
	}

	Task* task = tasksRepository->find(id);
	if (!task) {
		std::cout << "Task with ID " << id << " not found!" << std::endl;
		return;
	}

	tasksRepository->deleteTask(id);
	std::cout << "Task delete successfully!" << std::endl;
}

void Command::getTask(const MyString& name) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user!" << std::endl;
		return;
	}

	const MyVector<Task>& allTasks = tasksRepository->getTask();
	unsigned tasksCount = allTasks.size();

	for (size_t i = 0; i < tasksCount - 1; i++) {
		size_t minIndex = i;

		for (size_t j = i + 1; j < tasksCount; ++j) {
			if (allTasks[j].getId() < allTasks[minIndex].getId()) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			//std::swap(allTasks[i], allTasks[minIndex]);
		}
	}

	Task* task = tasksRepository->find(name);

	if (!task) {
		std::cout << "Task with name \"" << name << "\" not found!" << std::endl;
		return;
	}

	const std::tm* dueDate = &task->getDueDate();

	std::cout << "Task name: " << task->getName() << std::endl;
	std::cout << "Task ID: " << task->getId() << std::endl;
	std::cout << "Due date: " << std::asctime(dueDate) << std::endl;
	std::cout << "Status: " << task->getStatusStr() << std::endl;
	std::cout << "Task desc: " << task->getDescription() << std::endl;
}

void Command::getTask(unsigned id) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user!" << std::endl;
		return;
	}

	Task* task = tasksRepository->find(id);

	if (!task) {
		std::cout << "Task with ID " << id << " not found!" << std::endl;
		return;
	}

	const std::tm* dueDate = &task->getDueDate();

	std::cout << "Task name: " << task->getName() << std::endl;
	std::cout << "Task ID: " << task->getId() << std::endl;
	std::cout << "Due date: " << std::asctime(dueDate) << std::endl;
	std::cout << "Status: " << task->getStatusStr() << std::endl;
	std::cout << "Task desc: " << task->getDescription() << std::endl;
}

void Command::finishTask(unsigned id) {
	const User* user = usersRepository->getLoggedUserConst();
	if (!user) {
		std::cout << "User is not logged! Please, log in or register new user!" << std::endl;
		return;
	}

	tasksRepository->startTask(id);
	std::cout << "Task finished successfully!" << std::endl;
}

void Command::addCollaboration(const MyString& name) {
	const User* creator = usersRepository->getLoggedUserConst();
	if (!creator) {
		std::cout << "User is not logged in. Please log in or register." << std::endl;
		return;
	}

	// Check if a collaboration with the same name already exists
	if (collaborationsRepository->findCollaboration(name)) {
		std::cout << "Collaboration already exists." << std::endl;
		return;
	}

	static bool isRandInitialized = false;
	if (!isRandInitialized) {
		srand(time(NULL));
		isRandInitialized = true;
	}
	int id = rand();

	Collaboration collaboration(name, creator->getUsername(), id);
	collaboration.addUser(*creator); // Add the creator as the first member
	collaborationsRepository->addCollaboration(collaboration);

	std::cout << "Collaboration added successfully!" << std::endl;
}

void Command::deleteCollaboration(const MyString& name) {
	const User* loggedInUser = usersRepository->getLoggedUserConst();
	if (!loggedInUser) {
		std::cout << "User is not logged in. Please log in or register." << std::endl;
		return;
	}

	// Check if the logged-in user is the creator of the collaboration
	Collaboration* collaborationToDelete = collaborationsRepository->findCollaboration(name);
	if (!collaborationToDelete) {
		std::cout << "Collaboration not found." << std::endl;
		return;
	}

	if (collaborationToDelete->getCreator() != loggedInUser->getUsername()) {
		std::cout << "Only the creator of the collaboration can delete it." << std::endl;
		return;
	}

	// Delete all tasks associated with the collaboration
	MyVector<CollaborationTask>& tasks = collaborationToDelete->getCollaborationTasks();
	size_t tasksCount = tasks.size();

	for (size_t i = 0; i < tasksCount; i++) {
		const Task& task = tasks[i].getTask();
		collaborationsRepository->removeTaskFromCollaboration(name, task.getId());
	}

	// Remove the collaboration from the repository
	collaborationsRepository->deleteCollaboration(name, collaborationToDelete->getCreator());

	std::cout << "Collaboration deleted successfully!" << std::endl;
}

void Command::listCollaborations() {
	const User* loggedInUser = usersRepository->getLoggedUserConst();
	if (!loggedInUser) {
		std::cout << "User is not logged in. Please log in or register." << std::endl;
		return;
	}

	std::cout << "Collaborations for user " << loggedInUser->getUsername() << ":" << std::endl;

	// Get all collaborations from the repository
	const MyVector<Collaboration>& collaborations = collaborationsRepository->getCollaborations();

	for (size_t i = 0; i < collaborations.size(); i++) {
		const Collaboration& collaboration = collaborations[i];

		// Check if the logged-in user is the creator or part of the work group
		if (collaboration.getCreator() == loggedInUser->getUsername() ||
			collaboration.isUserInWorkGroup(loggedInUser->getUsername())) {

			std::cout << "Collaboration Name: " << collaboration.getName() << std::endl;
			std::cout << "Collaboration ID: " << collaboration.getId() << std::endl;
			std::cout << "Creator: " << collaboration.getCreator() << std::endl;
			std::cout << std::endl;
		}
	}
}

void Command::addUser(const MyString& collabName, const MyString& username) {
	const User* loggedInUser = usersRepository->getLoggedUserConst();
	if (!loggedInUser) {
		std::cout << "User is not logged in. Please log in or register." << std::endl;
		return;
	}

	// Find the collaboration
	Collaboration* collaboration = collaborationsRepository->findCollaboration(collabName);
	if (!collaboration) {
		std::cout << "Collaboration not found." << std::endl;
		return;
	}

	// Check if the logged-in user is the creator of the collaboration
	if (collaboration->getCreator() != loggedInUser->getUsername()) {
		std::cout << "Only the creator of the collaboration can add users." << std::endl;
		return;
	}

	// Check if the user is already in the work group
	if (collaboration->isUserInWorkGroup(username)) {
		std::cout << "User is already in the work group of collaboration." << std::endl;
		return;
	}

	// Add the user to the work group of the collaboration
	User userToAdd(username, loggedInUser->getPassword());
	collaboration->addUser(userToAdd);

	std::cout << "User added to collaboration."<< std::endl;
}

void Command::assignTask(const MyString& collabName, const MyString& username, const MyString& name, const std::tm& dueDate, const MyString& desc) {
	const User* loggedInUser = usersRepository->getLoggedUserConst();
	if (!loggedInUser) {
		std::cout << "User is not logged in. Please log in or register." << std::endl;
		return;
	}

	Collaboration* collaboration = collaborationsRepository->findCollaboration(collabName);
	if (!collaboration) {
		std::cout << "Collaboration not found." << std::endl;
		return;
	}

	if (collaboration->getCreator() != loggedInUser->getUsername()) {
		std::cout << "Only the creator of the collaboration can assign tasks." << std::endl;
		return;
	}

	/*CollaborationTask newTask(name, dueDate, desc, collaboration->getCollaborationTasks());
	newTask.setAssignee(username);
	collaboration->addTask(newTask);*/
	std::cout << "Task assigned successfully to " << username << "!" << std::endl;
}

void Command::listTasks(const MyString& collabName) {

}

void Command::logout() {
	if(usersRepository->getLoggedUserConst()) {
		usersRepository->logOutUser();
		std::cout << "Logged out! Goodbye!" << std::endl;
		std::cout << std::endl;
	}
}

void Command::writeToFile() const
{
	std::ofstream ofs("TaskManager.dat", std::ios::out | std::ios::binary);
	if (!ofs.is_open())
		throw "Error";

	const MyVector<User>& users = usersRepository->getUsers();
	unsigned countOfUsers = users.size();
	ofs.write((const char*)&countOfUsers, sizeof(unsigned));
	for (int i = 0; i < countOfUsers; i++)
		users[i].writeToFile(ofs);
	/*size_t countOfTasks = _tasks.size();
	ofs.write((const char*)&countOfTasks, sizeof(size_t));*/
	/*for (int i = 0; i < countOfTasks; i++)
		_tasks[i].writeToFile(ofs);*/

	ofs.clear();
	ofs.close();
}
void Command::readFromFile()
{
	std::ifstream ifs("TaskManager.dat", std::ios::in | std::ios::binary);
	if (!ifs.is_open())
		throw "Error";

	unsigned countOfUsers = 0;
	ifs.read((char*)&countOfUsers, sizeof(unsigned));
	for (int i = 0; i < countOfUsers; i++) {
		User read;
		read.readFromFile(ifs);
		_users.push_back(read);
	}
	/*size_t countOfTasks;
	ifs.read((char*)&countOfTasks, sizeof(size_t));*/
	//for (int i = 0; i < countOfTasks; i++)
	//{
	//	Task read;
	//	read.readFromFiLe(ifs);
	//	_tasks.push_back(read);
	//}

	ifs.clear();
	ifs.close();
}
Command::~Command()
{
	writeToFile();
}