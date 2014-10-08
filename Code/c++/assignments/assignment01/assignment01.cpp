#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout <<"Number"<<" Square"<<" Cube"<<endl
		 <<"======"<<" ======"<<" ===="<<endl;
	
	for(int i = 0; i <= 10; ++i)
	{
		cout <<i <<"\t" << i * i <<"\t" << i * i * i <<endl;
	}
	cout <<"Number"<<" Square"<<" Cube"<<endl
		 <<"======"<<" ======"<<" ===="<<endl;
		 
	int limit = 10;
	int i = 0;
	while(i <= limit)
	{
		
		cout <<i <<"\t" << i * i <<"\t" << i * i * i <<endl;
		++i;
	}
	i = 0;
	cout <<"Number"<<" Square"<<" Cube"<<endl
		 <<"======"<<" ======"<<" ===="<<endl;
	do
	{
		cout <<i <<"\t" << i * i <<"\t" << i * i * i <<endl;
		++i;
	}while( i <= limit);
	return 0;
}
