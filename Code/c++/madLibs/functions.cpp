//functions.cpp



#include <sstream>
#include <string>
#include <iostream>
#include <vector>

int askForInt(const std::string& question, int high, int low)
{
	int ret;
	do
	{
		std::cout << question  << std::endl;
		std::string str;
		std::getline(std::cin, str);
		std::stringstream ss(str);
		ss >> ret;
		if((ss) && (ret >= low && ret <= high))
		{
			break;
		}
		else
		{
			std::cout << "Try Again." << std::endl;
			continue;
		}
		
	}while(true);
	return ret;
}

void welcomePlayer()
{
	std::cout << "Welcome to Mad Libs.\n\n"
		 << "Please provide the following to help create a new story.\n\n";
}

std::string askText(const std::string& question)
{
	std::string ret;
	std::cout << question;
	std::getline(std::cin, ret);
	return ret;
}

void tellStory(const std::string& aName,
			   const std::string& aNoun,
			   int aNumber,
			   const std::string& aBodyPart,
			   const std::string& aVerb);
{
	std::cout << "\nHere is your story:\n\n"
			 << "The famous explorer, " << aName
			 << ", had nearly given up his life long quest to find\n"
			 << "the lost city of " << aNoun << " when one day, "
			 << "the " << aNoun << "found the explorer.\n"
			 << "Surrounded by " << aNumber << " " << aNoun
			 << ", a tear came to his " << aBodyPart << ".\n"
			 << "After all this time his quest was finally over."
			 << " And then, the " << aNoun << "\npromptly devoured "
			 << aName << ". The moral of the story? Be careful what you "
			 << aVerb << " for.";
}













