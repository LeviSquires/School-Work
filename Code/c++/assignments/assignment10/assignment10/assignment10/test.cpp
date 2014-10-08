#include <iostream>
#include <string>

#include "date.h"
#include "prototypes.h"

int main()
{
    std::cout << "Testing the explicit ctor:" <<std::endl;  
    Date then(29, 2, 2012);
    std::cout << "Leap day, this year: " << then.toString() << std::endl;
    then.addYears(3);
    std::cout << "Adding three years to it: " << then.toString() << std::endl << std::endl;

    std::cout << "Testing the default ctor:" <<std::endl;  
    Date now;
    std::cout << "The date right now: " << now.toString() << std::endl;
    now.addYears(-10);
    std::cout << "The Date ten years ago: " << now.toString() << std::endl << std::endl;


    std::cout << "Creating a date object:" <<std::endl;  
    Date dateTest1(31, 8, 2006);
    std::cout << "The date: " << dateTest1.toString() << std::endl;
    dateTest1.addMonths(10);
    std::cout << "The Date ten months later: " << dateTest1.toString() << std::endl;
    dateTest1.addMonths(-19);
    std::cout << "The Date nineteen months before: " << dateTest1.toString() << std::endl << std::endl;


    std::cout << "Creating a date object, St. Patrick's day, long ago:" <<std::endl;  
    Date dateTest2(17, 3, 1066);
    std::cout << "The date: " << dateTest2.toString() << std::endl;
    dateTest2.addDays(7);
    std::cout << "Adding a week: " << dateTest2.toString() << std::endl;
    dateTest2.addDays(364);
    std::cout << "Adding a year less a day: " << dateTest2.toString() << std::endl;
    dateTest2.addDays(-500);
    std::cout << "Subracting five hundred Days: " << dateTest2.toString() << std::endl << std::endl;

	system("pause");
    return 0;
}

