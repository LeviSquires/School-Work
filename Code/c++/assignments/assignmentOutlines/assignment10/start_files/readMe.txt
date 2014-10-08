Assignment 10

Pseudo Code
	Using the start_files we were given and a mixture of my pseudo code and the teachers. This project was simply implementing the pseudo code we 
	started with.
	
void Date::addMonths(int months)    
{
	int a = months / 12; //If months is a multiple of 12 it will add that value straight to _years.
	
	_year = _year + a;
	
	int b = months % 12; //if months does not divide evenly into 12 this takes the remaining months and add them to _months.
	
	_month = _month + b;
	
	if(_month > 12) //if month goes over 12 increase years.
	{
		++_year;
		int temp = _month % 12;
		_month = 0;
		_month = temp;
	}
	if(_month < 0) //if months goes below 0 decrease years.
	{
		--_year;
		int temp = _month % 12;
		_month = 0;
		_month = 12 + temp;
	}
}

void Date::addYears(int years)
{
	if(years != 0)
	{
		_year = _year + years; //simply add years to _years.
		if(_month == 2 && _day == 29 && years % 4 != 0)//check for leap year.
		{
			_day = 28;
		}
	}
}

bool Date::isLeapDay(int day, int month, int year) 
{
	if(day == 29 && month == 2 && isLeapYear(year)) //checks for leapday.
	{
		return true;
	}
	return false;
}

void Date::addDay(bool forward)
{
	if(forward)
	{
		if(_day < maxDay(_month, _year)) //as long as _day is lower then maxDay just increase _day.
		{
			++_day;
		}
		else
		{
			_day = 1; //if _day goes over maxDay set _day to 1 and increase month.
			++_month;
			if(_month > 12) //if _month exceeds 12 increase _year.
			{
				_month = 1;
				++_year;
			}
		}
	}
}

int Date::maxDay(int month, int year)
{
	if (isLeapYear(year) && month == 2) //max days for February on leap year.
	{
		return 29;
	}
	else
		return DAYS_PER_MONTH[month]; //returns maxDay based on the array.
}


Everything else we needed was already given.

For some reason my addmonth function is not working. It worked before but now is just saying invalid date and is displaying no errors.