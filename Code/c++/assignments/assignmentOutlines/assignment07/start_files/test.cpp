#include <iostream>
#include <string>

#include "prototypes.h"

int main()
{
    //1)create and display a Date object for July 7, 2001
    
    //2)create and display a Date object for right now

    int command = askForInt("\n\nEnter a custom date?\n1 - yes\n2 - no\n: ", 2, 1);
    while(command != 2)
    {
        int year = askForInt("Year (1 - 5000): ", 5000, 1);
        int month = askForInt("Month: (1 - 12): ", 12, 1);
        int day = askForInt("Day: (1 - 31): ", 31, 1);

        //3) Create and display a date object for the data entered by the user
        command = askForInt("\n\nEnter a custom date?\n1 - yes\n2 - no\n: ", 2, 1);
        
    }    
    return 0;
}

