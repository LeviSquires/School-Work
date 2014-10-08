#if !defined(CHESS_PIECE_H__)
#define CHESS_PIECE_H__
#include "square.h"


class ChessPiece
{
public:
    virtual void Draw(const Square& sqr); 

};

#endif
