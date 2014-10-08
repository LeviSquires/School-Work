#if !defined(DATE_H__)
#define DATE_H__

#include <string>
#include <ostream>

class Date
{
public:
    Date(int day, int month, int year);
    Date();
    std::string toString() const;
    bool isValid() const;
    static bool isLeapYear(int year);
    bool isLeapYear() const;
    static bool isLeapDay(int day, int month, int year); 
    bool isLeapDay() const;

    int getYear() const {if(isValid() == false){} return _year;}
    int getMonth() const {if(isValid() == false){} return _month;}
    int getDay() const {if(isValid() == false){} return _day;}



    Date operator++(int);
    Date& operator++();


    void addDay(bool forward);
    
        
    void addYears(int years);    
    void addMonths(int months);    
    void addDays(int days);    

    static int maxDay(int month, int year);


private:
    
    int _year;
    int _month;
    int _day;
    static const std::string MONTH_STRINGS[];      
    static const int DAYS_PER_MONTH[];
    static const int MIN_MONTH = 1;
    static const int MAX_MONTH = 12;
    static const int MIN_DAY = 1;

};


std::ostream& operator<<(std::ostream& os, const Date& date);
bool operator > (const Date& date1, const Date& date2);
bool operator >= (const Date& date1, const Date& date2);
bool operator == (const Date& date1, const Date& date2);
bool operator != (const Date& date1, const Date& date2);


#endif
