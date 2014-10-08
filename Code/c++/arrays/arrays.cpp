#include <iostream>
#include <string>

int main()
{
	std::string word1 = "Game";
	std::string word2("Over");
	std:: string word3(3, '!');
	
	std::cout << word1 << std::endl;
	std::cout << word2 << std::endl;
	std::cout << word3 << std::endl;
	
	std::string phrase = word1 + " " + word2 + word3;
	
	std::cout << "The phrase is: " << phrase << std::endl;
	
	std::cout << "Phrase has: " << phrase.size() << " characters.\n";
	std::cout << "The character at index zero is: " << phrase[0] << std::endl;
	std::cout << "Changing the character at position 0...\n";
	phrase[0] = 'L';
	std::cout << "The phrase is now: " << phrase << std::endl;
	
	for(unsigned i = 0; i < phrase.size(); ++i)
	{
		std::cout << "The phrase at index " << i << " is "
				  << phrase[i] << std::endl;
	}
	
	std::cout << " \nThe sequence \'Over\' begins at index: ";
	std::cout << phrase.find("Over") << std::endl;
	
	std::cout << " \nThe sequence \'Eggplant\' begins at index: ";
	std::cout << phrase.find("Eggplant") << std::endl;
	
	if(phrase.find("Eggplant") == std::string::npos)
	{
		std::cout << "\'Eggplant\' not found.\n";
	}
	
	phrase.erase(4, 5);// erase 5 indexes starting from position 4
	std::cout << "The phrase is now: " << phrase << std::endl;
	
	phrase.erase(4);
	std::cout << "The phrase is now: " << phrase << std::endl;
	
	phrase.erase();
	std::cout << "The phrase is now: " << phrase << std::endl;
	
	if(phrase.empty() == true)
	{
		std::cout << "\nThe phrase is empty.\n" << std::endl;
	}
	return 0;
}