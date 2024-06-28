#include "HelperFunctions.h"

bool isDigit(char s)
{
	return s <= '9' && s >= '0';
}
unsigned getDigitFromChar(char s)
{
	if (!isDigit(s))
		return 10;
	return s - '0';
}
unsigned getNumFromStr(const MyString& str)
{
	size_t len = str.getSize();
	unsigned mult = 1;
	unsigned res = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		res += mult * getDigitFromChar(str[i]);
		mult *= 10;
	}
	return res;
}

// Utility function to convert std::tm to std::time_t
std::time_t toTimeT(const std::tm& t) {
	std::tm temp = t;
	return std::mktime(&temp);
}

bool isSameDate(const std::tm& date1, const std::tm& date2) {
	return (date1.tm_year == date2.tm_year &&
		date1.tm_mon == date2.tm_mon &&
		date1.tm_mday == date2.tm_mday);
}

bool isToday(const std::tm& date) {
	std::time_t now = std::time(nullptr);
	std::tm* now_tm = std::localtime(&now);

	return (date.tm_year == now_tm->tm_year &&
		date.tm_mon == now_tm->tm_mon &&
		date.tm_mday == now_tm->tm_mday);
}