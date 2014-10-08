#include <iostream>
#include <string>

#include "critter.h"
#include "randgen.h"

//tricks
const std::string Critter::TRICKS[] =
{
	"Roll Over", "Jump", "Speak", "Do a Flip"
};

const unsigned Critter::NUM_TRICKS = sizeof(Critter::TRICKS) / sizeof(Critter::TRICKS[0]);


Critter::Critter(int hunger, int boredom) : m_Hunger(hunger), m_Boredom(boredom)//This is initialization.
{
	
}

std::string Critter::getMood() const
{
	std::string mood;
	if(m_Hunger + m_Boredom > MAD)
	{
		return "mad";
	}
	if(m_Hunger + m_Boredom > FRUSTRATED)
	{
		return "frustrated";
	}
	if(m_Hunger + m_Boredom > OKAY)
	{
		return "okay";
	}
	return "happy";
}
	void Critter::passTime(int time)
	{
		m_Hunger += time;
		m_Boredom += time;
	}
	
	void Critter::talk()
	{
		std::cout << "I'm a Critter and I feel " << getMood() << ".\n";
		passTime();
	}
	
	void Critter::eat(int food)
	{
		std::cout << "BURRRP!!" << std::endl;
		m_Hunger -= food;
		if(m_Hunger < 0)
		{
			m_Hunger = 0;
			
		}
		passTime();
	}
	
	void Critter::play(int fun)
	{
		std::cout << "Wheeee!" << std::endl;
		m_Boredom = ((m_Boredom - fun) < 0) ? 0 : (m_Boredom - fun);
		passTime();
	}
	
	void Critter::performTrick()
	{
		if(getMood() != "happy")
		{
			std::cout << "I don't feel like doing a trick.\n";
			return;
		}
		RandGen rg;
		unsigned choice = rg(NUM_TRICKS);
		std::cout << "I " << TRICKS[choice] << ".\n";
	}


