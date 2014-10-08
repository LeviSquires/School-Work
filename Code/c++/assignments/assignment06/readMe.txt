Instructions to run the program
	Use the nmake command from the command prompt to compile and run this program.
	
Pseudo Code
	Create an Array that holds all 52 cards. 
	Then create a pointer vector that points to the CARDS array.
	Each pointer in the vector will point to it's own card.
	This can be created using a for loop
		for(unsigned i = 0; i < DECK_SIZE; ++i)
		{
			vector.push_back(&CARDS[i]);
		}
	This loop assigns 52 pointers, one for each card.
	
	Using the RandGen object and random_shuffle you can shuffle the order that the pointers are displayed
	giving the appearance that the cards array was shuffled.
		RandGen rg;
		random_shuffle(vector.begin(), vector.end(), rg);
	
	To display the cards a for loop is needed.
		for(int i = 0; i < DECK_SIZE; ++i)
		{
			if(i % 13 == 0)//If the cards can be divided into 13 with no remainder then a new line will be created.
			{
				cout << endl;
			}
			cout << *vector[i] << " ";
		}
	
	
	