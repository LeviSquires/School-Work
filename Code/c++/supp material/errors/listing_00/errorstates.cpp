#include <iostream>
#include <vector>

using std::cin;
using std::cout;    
using std::vector;    

int main()
{
    vector<int> numbers;
    //prompt the user
    cout << "Enter positive numbers (-1 to quit): ";
    int input;
    cin >> input;
    while(input != -1)
    {
        if(input >= 0)
        {
            numbers.push_back(input);
        }
        cout << "Enter positive numbers (-1 to quit): ";
        cin >> input;
    }
    // more code...
    return 0;
}


