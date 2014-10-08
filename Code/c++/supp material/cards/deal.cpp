#include <algorithm> 
#include "deal.h"
#include "randgen.h"

using std::random_shuffle;


Deal::Deal()
{
	for(unsigned i = 0; i < Deck::DECK_SIZE; ++i)
	{
//		m_cards.push_back(&Deck::DECK[i]);
		m_cards.push_back(Deck::DECK + i); //pointer arithmetic  

	}
	Shuffle();
}

void Deal::Shuffle()
{
    RandGen rg;
	random_shuffle(m_cards.begin(), m_cards.end(), rg);
}

const Card* Deal::OneCard()
{
	const Card* p = m_cards.back();
	m_cards.pop_back();
	return p;
}



