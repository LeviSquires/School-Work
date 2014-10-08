//Start files for C++ Assignment 6 
// Ross Driedger


#include <iostream>
#include <string>

#include "prototypes.h"

using std::string;
using std::endl;
using std::cout;

const string CARDS[] =
{
    "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "TC", "JC", "QC", "KC", "AC",
    "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "TD", "JD", "QD", "KD", "AD",
    "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "JH", "QH", "KH", "AH",
    "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS", "QS", "KS", "AS"
};

unsigned const DECK_SIZE = sizeof(CARDS) / sizeof(string);

int const SHUFFLE_COMMAND = 1;
int const SHOW_COMMAND = 2;
int const QUIT_COMMAND = 3;
const char MENU[] = "Showing Cards Program:\n1 -- Shuffle Cards\n2 -- Show Deck\n3 -- Quit\n: ";
const char IM_OUTTA_HERE[] =  "Buh-bye!";


int main()
{
   
     
   int command = 0;
   do
   {
        command = askForInt(MENU, QUIT_COMMAND, SHUFFLE_COMMAND);
    
        switch(command)
        {
            case SHUFFLE_COMMAND:
              cout << "Shuffle Not Implemented.\n";
              break;
            case SHOW_COMMAND:
              cout << "Display Not Implemented.\n";
              break;
            case QUIT_COMMAND:
              break;    
        }
   }while(command != QUIT_COMMAND);
    
    cout << IM_OUTTA_HERE << endl;
    
    return 0;
    
}




