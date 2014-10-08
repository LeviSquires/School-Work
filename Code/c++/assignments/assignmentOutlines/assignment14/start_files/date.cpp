#include <iostream>
#include <sstream>
#include <ctime>
#include "date.h"


std::ostream& operator <<(std::ostream& os, const Date& date)
{
    os << date.toString();
    return os;
}

bool operator != (const Date& date1, const Date& date2)
{
    return !(date1 == date2); 
}

bool operator == (const Date& date1, const Date& date2)
{
    if(date1.getYear() == date2.getYear() &&
       date1.getMonth() == date2.getMonth() && 
       date1.getDay() == date2.getDay())
    {
        return true;
    }
    return false;
}


bool operator > (const Date& date1, const Date& date2)
{
    if(date1.getYear() > date2.getYear())
    {
        return true;
    }
    if(date1.getYear() < date2.getYear())
    {
        return false;
    }
    //Dates match
    if(date1.getMonth() > date2.getMonth())
    {
        return true;
    }
    if(date1.getMonth() < date2.getMonth())
    {
        return false;
    }
    //Months match
    if(date1.getDay() > date2.getDay())
    {
        return true;
    }
    return false;
}


bool operator>=(const Date& date1, const Date& date2)
{
    return (date1 > date2) || (date1 == date2);
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








