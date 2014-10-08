#if !defined(CELL_H)
#define CELL_H

#include <vector>
#include "path.h"


class Cell
{
public:
    Cell() : _heuristic(0),
             _start(false), 
             _end(false), 
             _block(false)
                              
    {}    
    void setStart();
    void setEnd();
    bool isEnd() const;
    bool isStart() const;        
    void setBlock();
    bool isBlock() const;
    void addPath(const Path& p);
    
    void calcWeight(double cost);    
    
    bool canMoveRight() const;
    bool canMoveDown() const;
    bool canMoveDownRight() const;
    bool canMoveDownLeft() const;
    bool canMoveLeft() const;
    bool canMoveUp() const;
    bool canMoveUpRight() const;
    bool canMoveUpLeft() const;
    
    double getCostRight() const;
    double getCostDown() const;
    double getCostDownRight() const;    
    double getCostDownLeft() const;
    double getCostLeft() const;
    double getCostUp() const;
    double getCostUpRight() const;    
    double getCostUpLeft() const;
    double getHeuristic() const
	{
		return _heuristic;
	}
    void setHeuristic(double h) const
	{
		_heuristic = h;
	}
    
    
protected:
    
    std::vector<Path> _paths;    
     
    mutable double _heuristic; 
    double _weight; 
    bool _start;
    bool _end;
    bool _block; 
};




#endif
