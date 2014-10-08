Assignment 19

Pseudo Code

	The only necessary changes was adding a few lines of code to the existing main function.
	
	int dx = 0; // represents the dx register -- where the answer goes

	int a = (numb1 & numb2);
	int b = (numb1 ^ numb2);
	int answer;

	while (a != 0)
	{
		a <<= 1; //Shifts left by 1
		answer = a ^ b;
		a &= b;
		b = answer;
	}
	dx = answer;