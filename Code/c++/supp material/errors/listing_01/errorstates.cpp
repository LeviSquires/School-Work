#include <iostream>
#include <vector>

using std::cin;
using std::cout;    
using std::vector;    
using std::endl;


int main()
{
    vector<int> numbers;
    //prompt the user
    cout << "Enter positive numbers (-1 to quit): ";
    int input;
    cin >> input;
    
    while(input != -1)
    {        
        if(cin.eof() == true) //end of file.
        {
            cout << "End of file found" << endl;
            break;
        }
        if(cin.fail() == true)
        {
            cout << "Error in input." << endl;
            break;
        }
        if(cin.bad() == true)
        {
            cout << "Serious error!" << endl;
            return 0;
        }
        
        
        if(input >= 0)
        {
            numbers.push_back(input);
        }
        cout << "Enter positive numbers (-1 to quit): ";
        cin >> input;
    }
    return 0;
}

