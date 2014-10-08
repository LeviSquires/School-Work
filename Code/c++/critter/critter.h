#include <string>

class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);
	void talk();
	void eat(int food = 5);
	void play(int fun = 5);
	void performTrick();
	
	
	
	
	
	

	

private:
	enum Mood
	{
		HAPPY,
		OKAY = 5,
		FRUSTRATED = 10,
		MAD = 15
	};
	
	static const std::string TRICKS[];
	static const unsigned NUM_TRICKS;
	
	std::string getMood() const;
	void passTime(int time = 1);
	
	int m_Hunger;
	int m_Boredom;
};