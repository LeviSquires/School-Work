#include <iostream>
#include <vector>
using namespace std;

#include "deal.h"
#include "card.h"

const unsigned DISPLAY_ROW = 13;

int main()
{
	Deal deal;
	unsigned i = 0;
	while(deal.Empty() == false)
	{
	    ++i;
		const Card* p = deal.OneCard();
		cout << p -> ToString() << " ";
		if(i == DISPLAY_ROW)
		{
		    i = 0;
		    cout << endl;
		}
	}
	cout << endl;
	return 0;

}
