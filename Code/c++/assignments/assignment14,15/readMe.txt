Assignment 14 and 15

Pseudo Code

Took the existing operator >(const Date& date1, const Date& date2) and changed it to 
operator <(const Date& mozartBirthday, const Date& beethovenBirthday).

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
Did the same thing with the existing operator>=() just changed it to <=.

bool operator<=(const Date& mozartBirthday, const Date& beethovenBirthday)
{
	return (mozartBirthday < beethovenBirthday) || (mozartBirthday == beethovenBirthday);
} 

int operator-(Date& date1, Date& date2)
{
	int date1DaysTotal = 0; //these int's are set as temp values to store the total number of days passed since year 0.
	int date2DaysTotal = 0;
	int ret = 0;
	for (int i = 0; i < date1.getYear(); ++i)// this loop adds 366 or 365 days to the total for each year from .getyear().
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
		for (int i = 0; i < date1.getMonth(); ++i) //this loops adds days to total days from .getmonth() provided the month isn't January.
		{
			date1DaysTotal += date1.DAYS_PER_MONTH[i];
		}
	}
	date1DaysTotal += date1.getDay();
	for (int i = 0; i < date2.getYear(); ++i) //same as above but for date2.
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
		for (int i = 0; i < date2.getMonth(); ++i) //same as above but for date2.
		{
			date2DaysTotal += date2.DAYS_PER_MONTH[i];
		}
	}
	date2DaysTotal += date2.getDay();
	ret = date1DaysTotal - date2DaysTotal; //Takes total from date1 and subtracts total from date2 then returns it.
	return ret;

}