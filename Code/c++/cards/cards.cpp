#include <iostream>
#include <string>

#include "cards.h"

const std::string Card::SUITS[] = {"C", "D", "H", "S"};
const std::string Card::PIPS[] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};

std::string Card::toString() const
{
	return PIPS[_pip] + SUITS[_suit};
}