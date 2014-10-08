#if !defined(SQUARE_H__)
#define SQUARE_H__
//#include "chesspiece.h"

class ChessPiece;

class Square
{
	void SetChessPiece(ChessPiece* p);
//...a bunch of stuff that we can safely omit for this example.
private:
    ChessPiece* _pPiece;
};
#endif


