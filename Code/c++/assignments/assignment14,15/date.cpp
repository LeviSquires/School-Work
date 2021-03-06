#include <iostream>
#include <sstream>
#include <ctime>
#include "date.h"


std::ostream& operator <<(std::ostream& os, const Date& date)
{
    os << date.toString();
    return os;
}

bool operator != (const Date& mozartBirthday, const Date& beethovenBirthday)
{
	return !(mozartBirthday == beethovenBirthday);
}

bool operator == (const Date& mozartBirthday, const Date& beethovenBirthday)
{
	if (mozartBirthday.getYear() == beethovenBirthday.getYear() &&
		mozartBirthday.getMonth() == beethovenBirthday.getMonth() &&
		mozartBirthday.getDay() == beethovenBirthday.getDay())
    {
        return true;
    }
    return false;
}

Date& Date::operator+=(int days)
{
	if (days < 0)
	{
		for (int i = 0; i >= days; --i)
		{
			addDay(false);
		}
	}
	else
	{
		for (int i = 0; i <= days; ++i)
		{
			addDay(true);
		}
	}
	return;
}

Date& Date::operator-=(int days)
{
	if (days < 0)
	{
		for (int i = 0; i >= days; --i)
		{
			addDay(true);
		}
	}
	else
	{
		for (int i = 0; i <= days; ++i)
		{
			addDay(false);
		}
	}
	return;
}

//done
bool operator < (const Date& mozartBirthday, const Date& beethovenBirthday)
{
	if (mozartBirthday.getYear() < beethovenBirthday.getYear())
    {
        return true;
    }
	if (mozartBirthday.getYear() > beethovenBirthday.getYear())
    {
        return false;
    }
    //Years match
	if (mozartBirthday.getMonth() < beethovenBirthday.getMonth())
    {
        return true;
    }
	if (mozartBirthday.getMonth() > beethovenBirthday.getMonth())
    {
        return false;
    }
    //Months match
	if (mozartBirthday.getDay() < beethovenBirthday.getDay())
    {
        return true;
    }
    return false;
}

//done
bool operator<=(const Date& mozartBirthday, const Date& beethovenBirthday)
{
	return (mozartBirthday < beethovenBirthday) || (mozartBirthday == beethovenBirthday);
} 

Date Date::operator++(int)
{
    addDay(true);
    Date ret(*this);
    return ret;
}


Date& Date::operator++()
{
    addDay(true);
    return *this;
}

Date Date::operator--(int)
{
	addDay(false);
	Date ret(*this);
	return ret;
}
Date& Date::operator--()
{
	addDay(false);
	return *this;
}

//done
int operator-(Date& date1, Date& date2)
{
	int date1DaysTotal = 0;
	int date2DaysTotal = 0;
	int ret = 0;
	for (int i = 0; i < date1.getYear(); ++i)
	{
		if (date1.isLeapYear(i))
		{
			date1DaysTotal += 366;
		}
		else
		{
			date1DaysTotal += 365;
		}
	}
	if (date1.getMonth() != 1)
	{
		for (int i = 0; i < date1.getMonth(); ++i)
		{
			date1DaysTotal += date1.DAYS_PER_MONTH[i];
		}
	}
	date1DaysTotal += date1.getDay();
	for (int i = 0; i < date2.getYear(); ++i)
	{
		if (date2.isLeapYear(i))
		{
			date2DaysTotal += 366;
		}
		else
		{
			date2DaysTotal += 365;
		}
	}
	if (date2.getMonth() != 1)
	{
		for (int i = 0; i < date2.getMonth(); ++i)
		{
			date2DaysTotal += date2.DAYS_PER_MONTH[i];
		}
	}
	date2DaysTotal += date2.getDay();
	ret = date1DaysTotal - date2DaysTotal;
	return ret;

}




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
    "Septenber",
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


int Date::maxDay(int month, int year)
{
    int ret = DAYS_PER_MONTH[month];
    if(isLeapYear(year) == true && month == 2)
    {
        ++ret;
    }
    return ret;
      
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
            _day = MIN_DAY;
            ++_month;
            if(_month > MAX_MONTH)
            {
                _month = MIN_MONTH;
                ++_year;
            }    
        }
    }
    else
    {
        if(_day <= MIN_DAY)
        {
            --_month;
            if(_month < MIN_MONTH)
            {
                _month = MAX_MONTH;
                --_year;
            } 
            _day = maxDay(_month, _year);
        }
        else
        {
            --_day;
        }
    }    
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

bool Date::isLeapDay(int day, int month, int year) 
{
    if(day == 29 && 
       month == 2 && 
       isLeapYear(year) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Date::addYears(int years)
{
    if(years == 0)
    {
        return;
    }
        

    if(isLeapDay() && !isLeapDay(_day, _month, _year + years))
    {
        _day = Date::DAYS_PER_MONTH[_month];
    }
    _year += years;
}
    
void Date::addMonths(int months)    
{
    if(months == 0)
    {
        return;
    }
    int deltayears = months / MAX_MONTH;
    int deltamonths = months % MAX_MONTH;
    int newMonth = 0;
    if(months > 0)
    {
        newMonth = (_month + deltamonths) % MAX_MONTH;
        if((_month + deltamonths) > MAX_MONTH)
        {
            ++deltayears;
        }
    }
    else
    {
        if((_month + deltamonths) < MIN_MONTH)
        {
            --deltayears;
            newMonth = _month + deltamonths + MAX_MONTH;
        }
        else
        {
            newMonth = _month + deltamonths;
        }       
    }
    if(_day > maxDay(newMonth, _year + deltayears))
    {
        _day = maxDay(newMonth, _year + deltayears);
    }
    _year += deltayears;
    _month = newMonth;
    
}

void Date::addDays(int days)
{
    if(days == 0)
    {
        return;
    }

    if(days < 0)
    {
        for(int i = 0; i > days; --i)
        {
            addDay(false);
        }
        return;
    }

    for(int i = 0; i < days; ++i)
    {
        addDay(true);
    }
}








