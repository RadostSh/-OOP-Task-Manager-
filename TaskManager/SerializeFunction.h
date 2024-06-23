#pragma once
#include "MyVector.hpp"
#include "MyString.h"
#include "User.h"
#include "Task.h"
#include <fstream>

void writeStringToFile(std::ofstream& ofs, const MyString& str);
MyString readStringFromFile(std::ifstream& ifs);