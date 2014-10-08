#include <string>

class Date
{
public :
	Date();
	
private :
	bool IsLeapYear() const;
	bool IsLeapDay() const;
	//const std::string MONTHS[12];
	int GetYear() const;
	int GetDay() const;
	int GetMonth() const;
	int _year;
	int _month;
	int _day;
	int SetYear();
	int SetMonth();
	int SetDay();
};