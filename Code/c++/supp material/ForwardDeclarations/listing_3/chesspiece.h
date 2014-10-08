#if !defined(CHESS_PIECE_H__)
#define CHESS_PIECE_H__
//remove the include
//#include "square.h"
//use a forward declaration
class Square;

class ChessPiece
{
public:
    virtual void Draw(const Square& sqr); 

};

#endif
