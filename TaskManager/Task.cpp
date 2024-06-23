#include "Task.h"
#include "SerializeFunction.h"

Task::Task(const MyString& name, const std::tm& due_data, const MyString& description, unsigned id) {
	_name = name;
	_due_data = due_data;
	_status = Status::ON_HOLD;
	_description = description;
	_id = id;
}

int Task::getId() const {
	return _id;
}

const MyString& Task::getName() const {
	return _name;
}

const std::tm& Task::getDueDate() const {
	return _due_data;
}

Status Task::getStatus() const {
	return _status;
}

const MyString& Task::getDescription() const {
	return _description;
}

void Task::setName(const MyString& name) {
	_name = name;
}

void Task::setNewStatus(Status status) {
	_status = status;
}

void Task::setDescription(const MyString& desc) {
	_description = desc;
}

bool Task::operator==(const Task& other) const {
	return _name == other._name && _description == other._description &&
		_due_data.tm_year == other._due_data.tm_year &&
		_due_data.tm_mon == other._due_data.tm_mon &&
		_due_data.tm_mday == other._due_data.tm_mday;
}

const MyString& Task::getStatusStr() const {
	switch (_status) {
	case Status::DONE:
		return "DONE";
	case Status::IN_PROCESS:
		return "IN_PROCESS";
	case Status::ON_HOLD:
		return "ON_HOLD";
	case Status::OVERDUE:
		return "OVERDUE";
	default:
		return "Unknown";
	}
}

void Task::writeToFile(std::ofstream& ofs) const {
	ofs.write((const char*)&_id, sizeof(int));
	writeStringToFile(ofs, _name);
	//writeTmToFile(ofs, _due_date);
	ofs.write((const char*)&_status, sizeof(Status));
	writeStringToFile(ofs, _description);
}

void Task::readFromFile(std::ifstream& ifs) {
	ifs.read((char*)&_id, sizeof(int));
	_name = readStringFromFile(ifs);
	//_due_date = readTmFromFile(ifs);
	ifs.read((char*)&_status, sizeof(Status));
	_description = readStringFromFile(ifs);
}