#if !defined(TEMPLATES_H__)
#define TEMPLATES_H__

#include <ostream>
#include <iomanip>

template
<class T>
void ShowBits(std::ostream& os, const T& thing)
{
	int bytes = sizeof(thing);
	int bits = bytes * CHAR_BIT / sizeof(int);

	unsigned  char* bit_data = reinterpret_cast<unsigned char*>(const_cast<T*>(&thing));

	for (int byteCounter = bytes - 1; byteCounter >= 0; --byteCounter)
	{
		unsigned char data = *(bit_data + byteCounter);
		for(int bitCounter = bits - 1; bitCounter >=  0; --bitCounter)
		{
			unsigned mask = 1U;
			std::cout << ((data >> bitCounter) & mask); //>> is a bit shift operator.
			if(bitCounter % 4 == 0)
			{
				std::cout << " ";
			}
		}
	}
}



#endif
