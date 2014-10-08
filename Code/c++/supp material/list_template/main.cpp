#include <iostream>
#include <string>
#include <exception>
#include "list.h"

using std::cout;
using std::endl;
using std::string;    
        

std::ostream& operator<<(std::ostream& os, const List<string>& lst)
{
	lst.OutPut(os);
	return os;
}
    


int main()
{
    List<string> list;
    
    cout << endl << "Outputting list first time: " << endl;

    list.PushFront("Or to take arms against a sea of troubles,"); 
    list.PushFront("The slings and arrows of outrageous fortune,"); 
    list.PushFront("Whether 'tis nobler in the mind to suffer"); 
    list.PushFront("To be, or not to be: that is the question:"); 
    list.PushBack("And by opposing end them? To die: to sleep;"); 
    list.PushBack("No more; and by a sleep to say we end"); 
    list.PushBack("The heart-ache and the thousand natural shocks"); 
    list.PushBack("That flesh is heir to, 'tis a consummation"); 
    list.PushBack("Devoutly to be wish'd."); 
    cout << list;


    {
        List<string> l2;
        l2 = list;
        cout << endl <<  "Outputting list created by the assignment operator: " << endl;
        cout << l2;
    }
    {
        List<string> l3(list);
        cout << endl << "Outputting list created by the copy ctor: " << endl;
        cout << l3;
        
    }
    
    cout << endl << "Outputting first list, last time: " << endl;
    cout << list;
    
    try
    {
        while(true)
        {
            std::string str = list.Front();
            std::cout << "Removing the front: "
                      << str << std::endl;
            list.PopFront();
            
        }
    }
    catch(std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    
	std::cin.get();

    return 0;
}
