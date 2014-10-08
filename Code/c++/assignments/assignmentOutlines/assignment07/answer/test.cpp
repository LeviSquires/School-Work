#include <iostream>
#include <string>

#include "date.h"
#include "prototypes.h"

int main()
{
    Date then(31, 7, 2001);
    std::cout << "The date object 'then': " << then.toString() << std::endl;
    Date now;
    std::cout << "The date object 'now': " << now.toString() << std::endl;

    int command = askForInt("\n\nEnter a custom date?\n1 - yes\n2 - no\n: ", 2, 1);
    while(command != 2)
    {
        int year = askForInt("Year (1 - 5000): ", 5000, 1);
        int month = askForInt("Month: (1 - 12): ", 12, 1);
        int day = askForInt("Day: (1 - 31): ", 31, 1);
        Date whenEver(day, month, year);
        std::cout << "Your date: " << whenEver.toString() << std::endl;
        command = askForInt("\n\nEnter a custom date?\n1 - yes\n2 - no\n: ", 2, 1);
        
    }    
    return 0;
}

