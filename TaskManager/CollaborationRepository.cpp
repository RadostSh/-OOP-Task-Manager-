#include "CollaborationRepository.h"

CollaborationsRepository* CollaborationsRepository::instance = nullptr;

CollaborationsRepository* CollaborationsRepository::getInstance() {
	if (!instance) {
		instance = new CollaborationsRepository();
	}
	return instance;
}

void CollaborationsRepository::freeInstance() {
	delete instance;
	instance = nullptr;
}

void CollaborationsRepository::addCollaboration(const Collaboration& collaboration) {
	_collaborations.push_back(collaboration);
}

void CollaborationsRepository::deleteCollaboration(const MyString& name, const MyString& creator) {
	for (size_t i = 0; i < _collaborations.size(); i++) {
		if (_collaborations[i].getName() == name && _collaborations[i].getCreator() == creator) {
			_collaborations.erase(i);
			break;
		}
	}
}

Collaboration* CollaborationsRepository::findCollaboration(const MyString& name) {
	for (size_t i = 0; i < _collaborations.size(); i++) {
		if (_collaborations[i].getName() == name) {
			return &_collaborations[i];
		}
	}
	return nullptr;
}

CollaborationTask* CollaborationsRepository::findTask(const MyString& taskName) {
	size_t length = _collaborationTask.size();
	for (size_t i = 0; i < length; ++i) {
		if (_collaborationTask[i].getName() == taskName) {
			return &_collaborationTask[i];
		}
	}
	return nullptr;
}

void CollaborationsRepository::removeTaskFromCollaboration(const MyString& collaborationName, unsigned taskId) {

	Collaboration* collaboration = findCollaboration(collaborationName);
	if (!collaboration) {
		std::cout << "Collaboration '" << collaborationName << "' not found." << std::endl;
		return;
	}

	// Find the task by ID within the collaboration
	MyVector<CollaborationTask>& tasks = collaboration->getCollaborationTasks();
	size_t tasksCount = tasks.size();

	for (size_t i = 0; i < tasksCount; i++) {
		if (tasks[i].getTask().getId() == taskId) {
			// Remove the task from the collaboration
			tasks.erase(i);
			std::cout << "Task removed from collaboration." << std::endl;
			return;
		}
	}

	std::cout << "Task not found in collaboration."<< std::endl;
}

const MyVector<Collaboration>& CollaborationsRepository::getCollaborations() const {
	return _collaborations; 
}