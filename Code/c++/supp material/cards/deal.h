#if !defined(DEAL_H__)
#define DEAL_H__

#include <vector>
#include "deck.h"

using std::vector;


class Deal
{
public:
	Deal();
	const Card* OneCard();
	bool Empty() const 
	{
		return (m_cards.size() == 0);
	}
private:
	void Shuffle();
	vector<const Card*> m_cards;
};





#endif
