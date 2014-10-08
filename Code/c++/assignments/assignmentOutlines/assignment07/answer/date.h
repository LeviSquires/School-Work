#if !defined(DATE_H__)
#define DATE_H__

#include <string>


class Date
{
public:
    Date(unsigned day, unsigned month, unsigned year);
    Date();
    std::string toString() const;
    bool isValid() const;
    static bool isLeapYear(unsigned year);
    bool isLeapYear() const;
    bool isLeapDay() const;

    unsigned getYear() const 
    {
        if(isValid() == false)
        {
        } 
        return _year;
    }


    unsigned getMonth() const {if(isValid() == false){} return _month;}
    unsigned getDay() const {if(isValid() == false){} return _day;}


private:
    
    unsigned _year;
    unsigned _month;
    unsigned _day;
    static const std::string MONTH_STRINGS[];      
    static const unsigned DAYS_PER_MONTH[];
    static const unsigned MIN_MONTH = 1;
    static const unsigned MAX_MONTH = 12;
    static const unsigned MIN_DAY = 1;
};






#endif
