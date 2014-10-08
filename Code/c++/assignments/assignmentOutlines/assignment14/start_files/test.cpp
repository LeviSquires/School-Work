#include <iostream>
#include <string>

#include "date.h"
#include "prototypes.h"

int main()
{

/*    
    Date mozartBirthday(27, 1, 1756);
    Date mozartDeathday(5, 12, 1791);
    
    Date beethovenBirthday(17, 12, 1770);
    Date beethovenDeathday(26, 3, 1827);

    std::cout << "Mozart's Birthday: " << mozartBirthday << std::endl;
    std::cout << "Mozart's Deathday: " << mozartDeathday << std::endl;

    std::cout << "Beethoven's Birthday: " << beethovenBirthday << std::endl;
    std::cout << "Beethoven's Deathday: " << beethovenDeathday << std::endl;

    if(mozartBirthday < beethovenBirthday)
    {
        std::cout << "Mozart was born before Beethoven." << std::endl;
    }
    if(mozartBirthday > beethovenBirthday)
    {
        std::cout << "Mozart was born after Beethoven." << std::endl;
    }

    mozartBirthday -= 7;
    std::cout << "One Week before Mozart's birth: " << mozartBirthday << std::endl; 

    mozartDeathday += 7;
    std::cout << "One Week after Mozart's death: " << mozartDeathday << std::endl; 

    beethovenBirthday++;
    std::cout << "The next day after Beethoven's birth: " << beethovenBirthday << std::endl; 

    ++beethovenDeathday;
    std::cout << "The next day after Beethoven's death: " << beethovenDeathday << std::endl; 


    beethovenBirthday--;
    --beethovenDeathday;
    std::cout << "Resetting Beethoven's days...." << std::endl;
    std::cout << "Beethoven lived for " << (beethovenDeathday - beethovenBirthday) << " days." << std::endl;

    std::cout << "Checking that subtraction works both ways (should be negative): " << (beethovenBirthday - beethovenDeathday) << " days." << std::endl;

*/

    int command = askForInt("\n\nEnter a custom date?\n1 - yes\n2 - no\n: ", 2, 1);
    while(command != 2)
    {
        int year = askForInt("Year (1 - 5000): ", 5000, 1);
        int month = askForInt("Month: ", INT_MAX, 0);
        int day = askForInt("Day: ", INT_MAX, 0);
        Date whenEver(day, month, year);
        std::cout << "Your date: " << whenEver.toString() << std::endl;
        command = askForInt("\n\nEnter a custom date?\n1 - yes\n2 - no\n: ", 2, 1);

    }


    std::cin.get();
    return 0;
}

