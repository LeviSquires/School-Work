#include "date.h"

Date::Date(int year, int month, int day) : _year(year), _month(month), _day(day)
{
}

bool Date::IsLeapYear() const
{
	if(_year % 4 == 0)
	{
		return true;
	}
	if(_year % 4 == 0 && _year % 100 != 0)
	{
		return true;
	}
	if(_year % 4 == 0 && _year % 100 == 0 && _year % 400 == 0)
	{
		return true;
	}
	return false;
}
/*
bool Date::IsLeapDay() const
{
	if(_month == 2 && _day == 29)
	{
		return true;
	}
	return false;
}

const std::string Date::MONTHS[] =
{
	"January", "February", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December"
}

int Date::GetDay()
{
	return _day;
}

int Date::GetYear()
{
	return _year;
}

int Date::GetMonth()
{
	return _month;
}
*/