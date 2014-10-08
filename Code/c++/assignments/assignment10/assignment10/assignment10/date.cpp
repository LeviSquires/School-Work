#include <iostream>
#include <sstream>
#include <ctime>
#include "date.h"

#pragma warning(disable : 4996)//disables localtime warning 

const std::string Date::MONTH_STRINGS[] = 
{
    "", //one based indexing
    "January",
    "February",
    "March",
    "April",
    "May", 
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

const int Date::DAYS_PER_MONTH[] =
{
    0, //one based indexing
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    
};      



Date::Date(int day, int month, int year) : _year(year), _month(month), _day(day)
{
    isValid();
}

Date::Date()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    _year = now -> tm_year + 1900;
    _month = now -> tm_mon + 1;
    _day = now -> tm_mday;
}




std::string Date::toString() const
{
    if(isValid() == false)
    {
        return std::string();
    }
    std::stringstream ss;
    ss  << MONTH_STRINGS[_month] << " " << _day << ", " <<  _year;
    return ss.str();            
}    


bool Date::isValid() const
{
    if(_month < MIN_MONTH || _month > MAX_MONTH)
    {
        std::cerr << "Invalid date " << std::endl;
        return false;
    }
    int daysThisMonth = maxDay(_month, _year);
     
    if(_day < MIN_DAY || _day > daysThisMonth)
    {
        std::cerr << "Invalid date " << std::endl;            
        return false;
        
    }
    return true;
}

bool Date::isLeapYear(int year)
{
    if(!(year % 4))
    {
        if(!(year % 100))
        {
            if(!(year % 400))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

bool Date::isLeapYear() const
{
    return isLeapYear(_year);
}

bool Date::isLeapDay() const
{
    return isLeapDay(_day, _month, _year);
}



int Date::maxDay(int month, int year)
{
	if (isLeapYear(year) && month == 2)
	{
		return 29;
	}
	else
		return DAYS_PER_MONTH[month];
}
	



void Date::addDay(bool forward)
{
	if(forward)
	{
		if(_day < maxDay(_month, _year))
		{
			++_day;
		}
		else
		{
			_day = 1;
			++_month;
			if(_month > 12)
			{
				_month = 1;
				++_year;
			}
		}
	}
}


bool Date::isLeapDay(int day, int month, int year) 
{
	if(day == 29 && month == 2 && isLeapYear(year))
	{
		return true;
	}
	return false;
}


void Date::addYears(int years)
{
	if(years != 0)
	{
		_year = _year + years;
		if(_month == 2 && _day == 29 && years % 4 != 0)
		{
			_day = 28;
		}
	}
}
  
void Date::addMonths(int months)    
{
	int a = months / 12;
	
	_year = _year + a;
	
	int b = months % 12; 
	
	_month = _month + b;
	
	if(_month > 12)
	{
		++_year;
		int temp = _month % 12;
		_month = 0;
		_month = temp;
	}
	if(_month < 0)
	{
		--_year;
		int temp = _month % 12;
		_month = 0;
		_month = 12 + temp;
	}
}
 
void Date::addDays(int days)
{
	if (days > 0)
	{
		for(int i = 0; i <= days; ++i)
		{
			addDay(days);
		}
	}
	for (int i = 0; i >= days; --i)
	{
		addDay(days);
	}
}








