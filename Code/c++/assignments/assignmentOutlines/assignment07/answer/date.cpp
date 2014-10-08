#include <iostream>
#include <sstream>
#include <ctime>
#include "date.h"

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
    "Octorber",
    "November",
    "December"
};

const unsigned Date::DAYS_PER_MONTH[] =
{
    0, //one based indexing
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    
};      



Date::Date(unsigned day, unsigned month, unsigned year) : _year(year), _month(month), _day(day)
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
        std::cerr << "Invalid month " << std::endl;
        return false;
    }
    unsigned daysThisMonth = DAYS_PER_MONTH[_month];
    if(_month == 2 && isLeapYear(_year))
    {
        ++daysThisMonth;
    } 
    if(_day < MIN_DAY || _day > daysThisMonth)
    {
        std::cerr << "Invalid day " << std::endl;            
        return false;
        
    }
    
    
    return true;
}

bool Date::isLeapYear(unsigned year)
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
    if(_day == 29 && 
       _month == 2 && 
       isLeapYear() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}





