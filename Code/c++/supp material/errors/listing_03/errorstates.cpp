#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;    
using std::cin;
using std::cout;    
using std::vector;    
using std::endl;

int main()
{
    vector<int> numbers;
    int input = 0;
    
    while(input != -1)
    {        
        //prompt the user
        cout << "Enter positive numbers (-1 to quit): ";
        string str; 
        cin >> str; //get the raw text that was entered
        stringstream ss(str); //create a string stream 
                              //object based on that string
        ss >> input;          // parse the object
        if(!ss) //report an error
        {
            if(cin.eof())
            {
                cout << "End of file found." << endl;
                cin.clear();
            }
            else
            {
                cout << "Error parsing " << ss.str() << endl;
            }
        }
        else
        {
            if(input >= 0)
            {
                numbers.push_back(input);
            }
        }
    }
    
    // more code...
    return 0;
}
