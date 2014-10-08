#pragma once

#include <ostream>
#include <string>
#include <map>

class Board
{
public:
	Board(void);
	~Board(void);

	void Reset();

	std::ostream& Draw(std::ostream&) const;

	enum Pieces 
	{
		NULL_PIECE = -1,
		WHITE_PAWN, 
		WHITE_KNIGHT,
		WHITE_BISHOP, 
		WHITE_ROOK,
		WHITE_QUEEN, 
		WHITE_KING,
		BLACK_PAWN, 
		BLACK_KNIGHT,
		BLACK_BISHOP, 
		BLACK_ROOK,
		BLACK_QUEEN, 
		BLACK_KING

	};


	void Move(const std::pair<unsigned, unsigned>& move);

	unsigned long long GetAllPieces() const;
private:
	void PlacePiece(Pieces p, unsigned square);
	void RemovePiece(unsigned square);
	const char* GetStringRep(unsigned square) const;

	unsigned long long _pieces[BLACK_KING + 1];
	static const char* PIECE_LABELS[];
};


template
<class T>
void ShowBits(std::ostream& os, const T& thing)
{
	int bytes = sizeof(thing);
	int bits = bytes * CHAR_BIT / sizeof(T);

	unsigned  char* bit_data = reinterpret_cast<unsigned char*>(const_cast<T*>(&thing));

	for (int byteCounter = bytes - 1; byteCounter >= 0; --byteCounter)
	{
		unsigned char data = *(bit_data + byteCounter);
		for (int bitCounter = bits - 1; bitCounter >= 0; --bitCounter)
		{
			unsigned mask = 1U;
			std::cout << ((data >> bitCounter) & mask); //>> is a bit shift operator.
			if (bitCounter % 4 == 0)
			{
				std::cout << " ";
			}
		}
	}
}