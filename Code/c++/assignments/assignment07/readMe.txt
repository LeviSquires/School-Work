Instructions to run this program
	Run nmake command from command prompt.
	
Pseudo Code
	Create a date.cpp and a date.h file. 
	These two files will contain all the information for the Date class.
	The Date class needs a constructor function that will pass 3 values: int year, string month and int day.
	Create getters and setters for year, month and day.
	
	Create isLeapYear stuff
		bool isLeapYear();
		bool isLeapDay();
		
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

		bool Date::IsLeapDay() const
		{
			if(_month == 2 && _day == 29)
			{
				return true;
			}
			return false;
		}
			