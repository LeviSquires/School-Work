#if !defined(BOARD_H)
#define BOARD_H

#include <ostream>
#include <string>
#include <vector>
#include <list>
#include "cell.h"
#include "route.h"

class Board
{
public:
    Board(unsigned width, unsigned height, double lowWeight, double highWeight, double equalWeight);   
	~Board()
	{
		delete [] _squares;
	}

    static const unsigned SPACES_PER_CELL_WIDTH = 16;
    static const unsigned SPACES_PER_CELL_HEIGHT = 8;
    
//    static const unsigned gridHeight() = 9;
//    static const unsigned gridWidth() = 6;
    const Cell& getCell(unsigned row, unsigned col) const;
    void show(std::ostream& os) const;
    
    std::string getCoordinates(unsigned index) const;
    
    bool next(std::ostream& os);
    
	static unsigned gridWidth()
	{
		return s_width;
	}

	static unsigned gridHeight()
	{
		return s_height;
	}

private:     
    void sortOpenNodes();
    void addNeighboursToOpenList(const Route& rt);
    double generateWeight(bool diagonal);

    unsigned _startIndex;
    unsigned _endIndex;
    std::vector<unsigned> _blocks;
    Cell* _squares;
    std::list<Route> _openList;
    std::vector<Route> _closedList;
    double _highWeight;        
    double _lowWeight; 
	double _equalWeight;
	static unsigned s_height;
	static unsigned s_width;
};
    


#endif

