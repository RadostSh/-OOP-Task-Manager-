#pragma once
#include <ctime>
#include "MyString.h"
#include "Task.h"

bool isDigit(char s);
unsigned getDigitFromChar(char s);
unsigned getNumFromStr(const MyString& str);
std::time_t toTimeT(const std::tm& t);
