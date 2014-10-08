#include <iostream>

#include "board.h"


Board::Board(void)
{
	Reset();
}


Board::~Board(void)
{
}


const char* Board::PIECE_LABELS[] = 
{
	"WP",
	"WN",
	"WB",
	"WR",
	"WQ",
	"WK",
	"BP",
	"BN",
	"BB",
	"BR",
	"BQ",
	"BK"

};


void Board::Reset()
{
	unsigned planes = sizeof(_pieces) / sizeof(_pieces[0]);
	for(unsigned i = 0; i < planes; ++i)
	{
		_pieces[i] = 0ULL;
	}

	//Pawns
	for(unsigned pawns = 0; pawns < 8; ++pawns)
	{
		PlacePiece(WHITE_PAWN, pawns + 48);
		PlacePiece(BLACK_PAWN, pawns + 8);
	}

	//Rooks
	PlacePiece(WHITE_ROOK, 56);
	PlacePiece(WHITE_ROOK, 63);
	PlacePiece(BLACK_ROOK, 0);
	PlacePiece(BLACK_ROOK, 7);

	//Knights
	PlacePiece(WHITE_KNIGHT, 57);
	PlacePiece(WHITE_KNIGHT, 62);
	PlacePiece(BLACK_KNIGHT, 1);
	PlacePiece(BLACK_KNIGHT, 6);

	//Bishops
	PlacePiece(WHITE_BISHOP, 58);
	PlacePiece(WHITE_BISHOP, 61);
	PlacePiece(BLACK_BISHOP, 2);
	PlacePiece(BLACK_BISHOP, 5);

	//Royalty
	PlacePiece(WHITE_QUEEN, 59);
	PlacePiece(WHITE_KING, 60);
	PlacePiece(BLACK_QUEEN, 3);
	PlacePiece(BLACK_KING, 4);


}

std::ostream& Board::Draw(std::ostream& os) const
{

	os << "\n\n\t  " << "  a    b    c    d    e    f    g    h" << std::endl; 
	os << "\t  " << "|----|----|----|----|----|----|----|----|" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t8 " << "| " << GetStringRep(0) << " | " << GetStringRep(1) << " | " << GetStringRep(2) << " | " << GetStringRep(3) 
		        << " | " << GetStringRep(4) << " | " << GetStringRep(5) << " | " << GetStringRep(6) << " | " << GetStringRep(7) << " |" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t  " << "|----|----|----|----|----|----|----|----|" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t7 " << "| " << GetStringRep(8) << " | " << GetStringRep(9) << " | " << GetStringRep(10) << " | " << GetStringRep(11) 
		        << " | " << GetStringRep(12) << " | " << GetStringRep(13) << " | " << GetStringRep(14) << " | " << GetStringRep(15) << " |" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t  " << "|----|----|----|----|----|----|----|----|" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t6 " << "| " << GetStringRep(16) << " | " << GetStringRep(17) << " | " << GetStringRep(18) << " | " << GetStringRep(19) 
		        << " | " << GetStringRep(20) << " | " << GetStringRep(21) << " | " << GetStringRep(22) << " | " << GetStringRep(23) << " |" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t  " << "|----|----|----|----|----|----|----|----|" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t5 " << "| " << GetStringRep(24) << " | " << GetStringRep(25) << " | " << GetStringRep(26) << " | " << GetStringRep(27) 
		        << " | " << GetStringRep(28) << " | " << GetStringRep(29) << " | " << GetStringRep(30) << " | " << GetStringRep(31) << " |" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t  " << "|----|----|----|----|----|----|----|----|" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t4 " << "| " << GetStringRep(32) << " | " << GetStringRep(33) << " | " << GetStringRep(34) << " | " << GetStringRep(35) 
		        << " | " << GetStringRep(36) << " | " << GetStringRep(37) << " | " << GetStringRep(38) << " | " << GetStringRep(39) << " |" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t  " << "|----|----|----|----|----|----|----|----|" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t3 " << "| " << GetStringRep(40) << " | " << GetStringRep(41) << " | " << GetStringRep(43) << " | " << GetStringRep(43) 
		        << " | " << GetStringRep(44) << " | " << GetStringRep(45) << " | " << GetStringRep(46) << " | " << GetStringRep(47) << " |" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t  " << "|----|----|----|----|----|----|----|----|" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t2 " << "| " << GetStringRep(48) << " | " << GetStringRep(49) << " | " << GetStringRep(50) << " | " << GetStringRep(51) 
		        << " | " << GetStringRep(52) << " | " << GetStringRep(53) << " | " << GetStringRep(54) << " | " << GetStringRep(55) << " |" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t  " << "|----|----|----|----|----|----|----|----|" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t1 " << "| " << GetStringRep(56) << " | " << GetStringRep(57) << " | " << GetStringRep(58) << " | " << GetStringRep(59) 
		        << " | " << GetStringRep(60) << " | " << GetStringRep(61) << " | " << GetStringRep(62) << " | " << GetStringRep(63) << " |" << std::endl; 
	os << "\t  " << "|    |    |    |    |    |    |    |    |" << std::endl; 
	os << "\t  " << "|----|----|----|----|----|----|----|----|" << std::endl; 


	return os;
}

void Board::Move(const std::pair<unsigned, unsigned>& move)
{
	Pieces p = NULL_PIECE;
	unsigned planes = sizeof(_pieces) / sizeof(_pieces[0]);
	unsigned long long mask = 1ULL;
	mask <<= move.first;
	for(unsigned i = 0; i < planes; ++i)
	{
		if(_pieces[i] & mask)
		{
			p = static_cast<Pieces>(i);
			RemovePiece(move.first);
			PlacePiece(p, move.second);
			return;
		}		
	}



}


const char* Board::GetStringRep(unsigned square) const
{
	unsigned long long positions = GetAllPieces();
	unsigned long long mask = 1ULL;
	
	
	mask <<= square;
	
	

	if(!(positions & mask))
	{
		return "  ";
	}

	unsigned planes = sizeof(_pieces) / sizeof(_pieces[0]);
	for(unsigned i = 0; i < planes; ++i)
	{
		if(_pieces[i] & mask)
		{
			return PIECE_LABELS[i];
		}		
	}
	return "  ";
}



unsigned long long Board::GetAllPieces() const
{
	unsigned planes = sizeof(_pieces) / sizeof(_pieces[0]);
	unsigned long long ret = 0ULL;
	for(unsigned i = 0; i < planes; ++i)
	{
		ret |= _pieces[i];
	}
	//ShowBits(std::cout, ret);
	//std::cout << std::endl;
	//std::cin.get();
	return ret;
}


void Board::PlacePiece(Pieces p, unsigned square)
{
	RemovePiece(square);
	unsigned long long mask = 1ULL;
	
//	ShowBits(std::cout, mask);
//	std::cout << std::endl;
	mask <<= square;
//	ShowBits(std::cout, mask);
//	std::cout << std::endl;

//	ShowBits(std::cout, _pieces[p]);
//	std::cout << std::endl;
	_pieces[p] |= mask;	//setting a bit
	//ShowBits(std::cout, _pieces[p]);
	//std::cout << std::endl;
	//std::cin.get();
}

void Board::RemovePiece(unsigned square)
{
	unsigned planes = sizeof(_pieces) / sizeof(_pieces[0]);
	unsigned long long mask = 1ULL;
	mask <<= square;
	for(unsigned i = 0; i < planes; ++i)
	{
		_pieces[i] &= ~mask; //clearing a bit
	}


}

