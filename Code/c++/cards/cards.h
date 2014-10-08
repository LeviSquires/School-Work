#include <string>

class Card
{
public:
	enum Suit
	{
		C, D, H, S
	};
	
	enum Pip
	{
		_2, _3, _4, _5, _6, _7, _8, _9, _T, _J, _Q, _K, _A
	};
	
	Card(Suit s, Pip p) : _pip(p), _suit(s)
	{
	}
	
	Pip getPip() const
	{
		return _pip;
	}
	
	Suit getSuit() const
	{
		return _suit;
	}
	
	std::string toString() const;
	
		
	
	
private:
	static const std::string SUITS[];
	static const std::string PIPS[];
	Pip _pip;
	Suit _suit;
	
}