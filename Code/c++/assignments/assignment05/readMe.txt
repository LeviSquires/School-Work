Assignment05 - Fibonacci

Instructions to run this program.
	To run this program use the makefile or makefileNix while in this program's directory within the command prompt.
	
Pseudo Code
	First step is to copy any usable code from the recursive function.
	double fibonacci(unsigned term)
	{
	if(term == 0 || term == 1)
    {
        return 1;
    }
	This code is the same for both versions so it makes sense not to change it.
	
	Second step is to declare two variables 
	int a = 1;
	int b = 1;
	Both of these variables are set to 1 because the first mathematical operation is adding 1 + 1 = 2.
	
	Third step is to create a for loop that will continue to add the two numbers together until a certain condition is met.
	for(unsigned int i = 2; i <= term; ++i)
	{
		double c = a + b; //variable c is set only as a temp value to hold the sum of additon
		b = a; // setting b = a ensures when the next time this loop runs the addition includes the two newest values.
		a = c; // setting a = c ensures when the next time this loop runs the addition includes the two newest values.
	}
	return a;
	You return a because it is = to both numbers added together.
	

Recursive Advantages/Disadvantages
	Recursive functions are less code then iterative functions and the code is generally easier to read.
	However as we saw in class the "tree diagram" that showcased each step of the recursive function showed how quickly the function gets 
	complicated and how much time it takes to reference each previous level.

	Therefore I think the best time to use recursion would be when a function only needs to call itself a few times with minimal calculations or
	if the function was given time to load in the background before it was displayed to the user.
	
Iteration Advantages/Disadvantages
	To do the same same thing iteratively takes more code and is harder to understand which is shown by this project.
	However as also shown in this project the iteration is done almost instantly while the recursion took several minutes.

	Therefore I think the best time to use iteration would be for loops that are run many times with high digit numbers(like this project).
		
	