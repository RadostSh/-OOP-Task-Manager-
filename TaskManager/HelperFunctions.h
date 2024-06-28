#pragma once
#include <ctime>
#include "MyString.h"
#include "Task.h"
#pragma warning(disable : 4996)

bool isDigit(char s);
unsigned getDigitFromChar(char s);
unsigned getNumFromStr(const MyString& str);
std::time_t toTimeT(const std::tm& t);
bool isSameDate(const std::tm& date1, const std::tm& date2);
bool isToday(const std::tm& date);