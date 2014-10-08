#include "board.h"
#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include "randgen.h"

double const SQRT_OF_2 = 1.4142135623731;

unsigned Board::s_height;
unsigned Board::s_width;



double Board::generateWeight(bool diagonal)
{

	if(_equalWeight > 0)
	{
		if(diagonal)
		{
			return _equalWeight * SQRT_OF_2;
		}
		return _equalWeight;
	}

	RandGen rg;
	double delta = (_highWeight - _lowWeight);
	if(delta < 0.01)
	{
		return _lowWeight;
	}

	double ret = rg(static_cast<unsigned>(delta * 100)) / 100.0;
	ret += _lowWeight;
	return ret;
		
}


Board::Board(unsigned width, unsigned height, double lowWeight, double highWeight, double equalWeight): 
	_squares(new Cell[width * height]), 
	_highWeight(highWeight),
	_lowWeight(lowWeight), 
	_equalWeight(equalWeight)
{
    RandGen rg;
    s_height = height;
	s_width = width;


    
    _startIndex = rg(gridWidth() * gridHeight());
    _endIndex = rg(gridWidth() * gridHeight());
    
    int xdistance = static_cast<int>(std::abs(static_cast<double>(_startIndex % gridWidth()) - (_endIndex % gridWidth())));
    int ydistance = static_cast<int>(std::abs(static_cast<double>(_startIndex / gridWidth()) - (_endIndex / gridWidth())));
    int manhattan = xdistance + ydistance;
    
    double factor = 1.0;
    while(manhattan <= ((gridWidth() + gridHeight()) * factor))
    {
        _startIndex = rg(gridWidth() * gridHeight());
        _endIndex = rg(gridWidth() * gridHeight());        
        xdistance = static_cast<int>(std::abs(static_cast<double>(_startIndex % gridWidth()) - (_endIndex % gridWidth())));
        ydistance = static_cast<int>(std::abs(static_cast<double>(_startIndex / gridWidth()) - (_endIndex / gridWidth())));
        manhattan = xdistance + ydistance;
		factor -= 0.01;
    } 
    
    _squares[_startIndex].setStart();
    _squares[_endIndex].setEnd();
    
    
    
    unsigned blocks = rg((gridWidth() + gridHeight()) * 2);
    
    for(unsigned i = 0; i < blocks; )
    {
        unsigned index = rg(gridWidth() * gridHeight());
        if(index != _startIndex && index != _endIndex)
        {
            std::vector<unsigned>::const_iterator it = find(_blocks.begin(), _blocks.end(), index);
            if(it == _blocks.end())
            {
                _squares[index].setBlock();
                ++i;
            }    
        }
    }
    
    //Add Paths -- down and to the right
    for(unsigned i = 0; i < gridWidth() * gridHeight(); ++i)
    {
        //consider _squares[i]
        
        if(_squares[i].isBlock())
        {
            continue;
        }
        
        //Square below
        if((i + gridWidth()) < (gridWidth() * gridHeight()))
        {
            if(_squares[i + gridWidth()].isBlock() == false)
            {

                double weight = generateWeight(false);
				
                _squares[i].addPath(Path(i, i + gridWidth(), weight));
                weight = generateWeight(false);
                _squares[i + gridWidth()].addPath(Path(i + gridWidth(), i, weight));
            }
        }
        //Square to the right
        if(((i + 1) % gridWidth()) != 0)
        {
            if(_squares[i + 1].isBlock() == false)
            {
                double weight = generateWeight(false);
                
                _squares[i].addPath(Path(i, i + 1, weight));
                weight = generateWeight(false);
                _squares[i + 1].addPath(Path(i + 1, i, weight));
            }
        }
        //Square to the bottom right
        if((i + gridWidth()) < (gridWidth() * gridHeight()) && ((i + 1) % gridWidth()) != 0)
        {
            unsigned index =  i + 1 + gridWidth();
            if(_squares[index].isBlock() == false)
            {
                double weight = generateWeight(true);
                
                _squares[i].addPath(Path(i, index, weight));
                weight = generateWeight(true);
                _squares[index].addPath(Path(index, i, weight));
            }
        }
        //Square to the bottom left
        if((i + gridWidth()) < (gridWidth() * gridHeight()) && 
            i  != 0 && (i % gridWidth()) != 0)
        {
            unsigned index =  i - 1 + gridWidth();
            if(_squares[index].isBlock() == false)
            {
                double weight = generateWeight(true);
                
                _squares[i].addPath(Path(i, index, weight));
                weight = generateWeight(true);
                _squares[index].addPath(Path(index, i, weight));
            }
        }

    }
    
    _openList.push_back(Route(_startIndex));

    
//    addNeighboursToOpenList(_startIndex);

}


bool beenThereDoneThat(const std::vector<Route>& routes, unsigned newIndex)
{
	for(std::vector<Route>::const_iterator it = routes.begin(); it != routes.end(); ++it)
	{
		if(it -> getTerminus() == newIndex)
		{
			return true;
		}
	}
	return false;
}

std::list<Route>::iterator lookForEntry(std::list<Route>& rt, unsigned newIndex)
{
	std::list<Route>::iterator ret = rt.begin();
	for(; ret != rt.end(); ++ret)
	{
		if(ret -> getTerminus() == newIndex)
		{
			return ret;
		}
	}
	return ret;

}

void Board::addNeighboursToOpenList(const Route& rt)
{


	if(_squares[rt.getTerminus()].canMoveRight())
    {
        unsigned newIndex = rt.getTerminus() + 1; 
		if(beenThereDoneThat(_closedList, newIndex) == false)
		{
			std::list<Route>::iterator it = lookForEntry(_openList, newIndex);
			if(it != _openList.end())
			{
				//The new path costs less than the existing path.  Replace.
				if(it -> getRouteWeight() > rt.getRouteWeight() + _squares[rt.getTerminus()].getCostRight())
				{
					*it = Route(rt, newIndex, _squares[rt.getTerminus()].getCostRight());
				}
			}
			else
			{
				_openList.insert(_openList.begin(), Route(rt, newIndex, _squares[rt.getTerminus()].getCostRight()));
			}


		}

    }

    if(_squares[rt.getTerminus()].canMoveLeft())
    {
        unsigned newIndex = rt.getTerminus() - 1; 
        if(beenThereDoneThat(_closedList, newIndex) == false)
        {
			std::list<Route>::iterator it = lookForEntry(_openList, newIndex);
			if(it != _openList.end())
			{
				//The new path costs less than the existing path.  Replace.
				if(it -> getRouteWeight() > rt.getRouteWeight() + _squares[rt.getTerminus()].getCostLeft())
				{
					*it = Route(rt, newIndex, _squares[rt.getTerminus()].getCostLeft());
				}
			}
			else
			{
				_openList.insert(_openList.begin(), Route(rt, newIndex, _squares[rt.getTerminus()].getCostLeft()));
			}
        }
    }

	if(_squares[rt.getTerminus()].canMoveUp())
    {
        unsigned newIndex = rt.getTerminus() - gridWidth(); 
        if(beenThereDoneThat(_closedList, newIndex) == false)
        {
			std::list<Route>::iterator it = lookForEntry(_openList, newIndex);
			if(it != _openList.end())
			{
				//The new path costs less than the existing path.  Replace.
				if(it -> getRouteWeight() > rt.getRouteWeight() + _squares[rt.getTerminus()].getCostUp())
				{
					*it = Route(rt, newIndex, _squares[rt.getTerminus()].getCostUp());
				}
			}
			else
			{
				_openList.insert(_openList.begin(), Route(rt, newIndex, _squares[rt.getTerminus()].getCostUp()));
			}
        }
    }
    if(_squares[rt.getTerminus()].canMoveDown())
    {
        unsigned newIndex = rt.getTerminus() + gridWidth();
		if(beenThereDoneThat(_closedList, newIndex) == false)
		{
			std::list<Route>::iterator it = lookForEntry(_openList, newIndex);
			if(it != _openList.end())
			{
				//The new path costs less than the existing path.  Replace.
				if(it -> getRouteWeight() > rt.getRouteWeight() + _squares[rt.getTerminus()].getCostDown())
				{
					*it = Route(rt, newIndex, _squares[rt.getTerminus()].getCostDown());
				}
			}
			else
			{
				_openList.insert(_openList.begin(), Route(rt, newIndex, _squares[rt.getTerminus()].getCostDown()));
			}


		}

    }

    if(_squares[rt.getTerminus()].canMoveDownRight())
    {
        unsigned newIndex = rt.getTerminus() + gridWidth() + 1;
        
		if(beenThereDoneThat(_closedList, newIndex) == false)
		{
			std::list<Route>::iterator it = lookForEntry(_openList, newIndex);
			if(it != _openList.end())
			{
				//The new path costs less than the existing path.  Replace.
				if(it -> getRouteWeight() > rt.getRouteWeight() + _squares[rt.getTerminus()].getCostDownRight())
				{
					*it = Route(rt, newIndex, _squares[rt.getTerminus()].getCostDownRight());
				}
			}
			else
			{
				_openList.insert(_openList.begin(), Route(rt, newIndex, _squares[rt.getTerminus()].getCostDownRight()));
			}


		}

    }
    if(_squares[rt.getTerminus()].canMoveUpLeft())
    {
        unsigned newIndex = rt.getTerminus() - (gridWidth() + 1);

		if(beenThereDoneThat(_closedList, newIndex) == false)
		{
			std::list<Route>::iterator it = lookForEntry(_openList, newIndex);
			if(it != _openList.end())
			{
				//The new path costs less than the existing path.  Replace.
				if(it -> getRouteWeight() > rt.getRouteWeight() + _squares[rt.getTerminus()].getCostUpLeft())
				{
					*it = Route(rt, newIndex, _squares[rt.getTerminus()].getCostUpLeft());
				}
			}
			else
			{
				_openList.insert(_openList.begin(), Route(rt, newIndex, _squares[rt.getTerminus()].getCostUpLeft()));
			}


		}

    }

    
    if(_squares[rt.getTerminus()].canMoveDownLeft())
    {
        unsigned newIndex = rt.getTerminus() + (gridWidth() - 1);
		if(beenThereDoneThat(_closedList, newIndex) == false)
		{
			std::list<Route>::iterator it = lookForEntry(_openList, newIndex);
			if(it != _openList.end())
			{
				//The new path costs less than the existing path.  Replace.
				if(it -> getRouteWeight() > rt.getRouteWeight() + _squares[rt.getTerminus()].getCostDownLeft())
				{
					*it = Route(rt, newIndex, _squares[rt.getTerminus()].getCostDownLeft());
				}
			}
			else
			{
				_openList.insert(_openList.begin(), Route(rt, newIndex, _squares[rt.getTerminus()].getCostDownLeft()));
			}


		}

    }
    if(_squares[rt.getTerminus()].canMoveUpRight())
    {
        unsigned newIndex = rt.getTerminus() - (gridWidth() - 1);
		if(beenThereDoneThat(_closedList, newIndex) == false)
		{
			std::list<Route>::iterator it = lookForEntry(_openList, newIndex);
			if(it != _openList.end())
			{
				//The new path costs less than the existing path.  Replace.
				if(it -> getRouteWeight() > rt.getRouteWeight() + _squares[rt.getTerminus()].getCostUpRight())
				{
					*it = Route(rt, newIndex, _squares[rt.getTerminus()].getCostUpRight());
				}
			}
			else
			{
				_openList.insert(_openList.begin(), Route(rt, newIndex, _squares[rt.getTerminus()].getCostUpRight()));
			}


		}

    }
   
}     

#ifndef CPP_11
bool compareRoutes(const Route& rt1, const Route& rt2)
{
    return rt1.getRouteWeight() < rt2.getRouteWeight();
}
#endif

void Board::sortOpenNodes()
{
#ifdef CPP_11
     _openList.sort([] (const Route& rt1, const Route& rt2){return rt1.getRouteWeight() < rt2.getRouteWeight();});
#else
     _openList.sort(compareRoutes);
#endif
}

const Cell& Board::getCell(unsigned row, unsigned col) const
{
    assert((row * gridWidth() + col) < (gridWidth() * gridHeight()));
    return _squares[row * gridWidth() + col];
}

void Board::show(std::ostream& os) const
{
    std::stringstream ss;
    ss << std::endl << std::string(SPACES_PER_CELL_WIDTH / 2, ' ');
    char ch = 'A';    
    for(unsigned i = 0; i < gridWidth(); ++i, ++ch)
    {
        ss << ch << std::string(SPACES_PER_CELL_WIDTH - 1, ' ');
    }    
            
	ss << std::endl << std::string(gridWidth() * SPACES_PER_CELL_WIDTH, '-') << std::endl;
	    
	for(unsigned i = 0; i < gridHeight(); ++i)
    {

        std::stringstream* streams[SPACES_PER_CELL_HEIGHT] = 
        {
            new std::stringstream,
            new std::stringstream,
            new std::stringstream,
            new std::stringstream,
            new std::stringstream,
            new std::stringstream,
            new std::stringstream,
            new std::stringstream(std::string(gridWidth() * SPACES_PER_CELL_WIDTH + 1, '-'))
                

        };
        
        for(unsigned k = 0; k < SPACES_PER_CELL_HEIGHT - 1; ++k)
        {
            *streams[k] << "|";
        }
        
        
        for(unsigned j = 0; j < gridWidth(); ++j)
        {
            const Cell& cell = getCell(i, j);
            /*We have a chunk of screen data that is 15 spaces with and 8 lines high. 
              This does not include the top or left border (shown for clarity)
              
              
                  |--------------|
                  |x.x   x.x  x.x|
                  |  \    |   /  |
                  |   \   |  /   |
                  |x.x--XX.X--x.x|
                  |   /   |  \   |
                  |  /    |   \  |
                  |x.x   x.x  x.x|
                  |--------------|
              
            */
            
            
            if(cell.canMoveUpLeft())
            {
                *streams[0] << std::fixed 
                           << std::setprecision(1) << cell.getCostUpLeft() << "   ";
                *streams[1] << "   \\   ";
                *streams[2] << "    \\  ";
                            
            }
            else
            {
                *streams[0] << "      ";
                *streams[1] << "       ";
                *streams[2] << "       ";
                
            }
            
            if(cell.canMoveUp())
            {
                *streams[0] << std::fixed 
                           << std::setprecision(1) << cell.getCostUp();
                *streams[1] << "|";
                *streams[2] << "|";
            }
            else
            {
                *streams[0] << "   ";
                *streams[1] << " ";
                *streams[2] << " ";                
            }
            if(cell.canMoveUpRight())
            {
                *streams[0] << "   " << std::fixed 
                          << std::setprecision(1) << cell.getCostUpRight() << "|";
                *streams[1] << "   /   |";
                *streams[2] << "  /    |";
                
            }
            else
            {
                *streams[0] << "      |";
                *streams[1] << "       |";
                *streams[2] << "       |";
                
            }

            
            if(cell.isBlock())
            {
                *streams[3] << "     Block     |";
            
            }
            else
            {            
                if(cell.canMoveLeft())
                {
                    *streams[3] << std::fixed 
                               << std::setprecision(1) << cell.getCostLeft() << "--";
                }
                else
                {
                    *streams[3] << "     ";
                }            
            
                if(cell.isStart())
                {
                    *streams[3] << "Start";
                }
                else
                {
                    if(cell.isEnd())
                    {
                        *streams[3] << " End ";
                    }
                    else
                    {
                        *streams[3] << "  "  << getCoordinates(i * gridWidth() + j) << " ";

                    }
                }
                
                
                
                if(cell.canMoveRight())
                {
                    *streams[3] << "--" << std::fixed 
                               << std::setprecision(1) << cell.getCostRight() << "|";
                }
                else
                {
                    *streams[3] << "     |";
                }
            }                
            


            if(cell.canMoveDownLeft())
            {
                *streams[4] << "    /  ";
                *streams[5] << "   /   ";
                *streams[6] << std::fixed 
                           << std::setprecision(1) << cell.getCostDownLeft() << "   ";
                            
            }
            else
            {
                *streams[4] << "       ";
                *streams[5] << "       ";
                *streams[6] << "      ";
                
            }


            if(cell.canMoveDown())
            {
                *streams[4] << "|";
                *streams[5] << "|";
                *streams[6] << std::fixed 
                           << std::setprecision(1) << cell.getCostDown();
            }
            else
            {
                *streams[4] << " ";
                *streams[5] << " ";                
                *streams[6] << "   ";
            }
            
                
            if(cell.canMoveDownRight())
            {
                *streams[4] << "  \\    |";
                *streams[5] << "   \\   |";
                *streams[6] << "   " << std::fixed 
                          << std::setprecision(1) << cell.getCostDownRight() << "|";
                
            }
            else
            {
                *streams[4] << "       |";
                *streams[5] << "       |";
                *streams[6] << "      |";
                
            }
            
        }
        
        *streams[3] << " " << (i + 1);
        for(unsigned k = 0; k < SPACES_PER_CELL_HEIGHT; ++k)
        {
            ss << streams[k] -> str() << std::endl;
            delete streams[k];    
        }
        
       
        
    }

    ss << "Start: " << getCoordinates(_startIndex) 
       << " End: " << getCoordinates(_endIndex)  
	   << " Currect Node: " << ((_closedList.size()) ? getCoordinates(_closedList[_closedList.size() - 1].getTerminus()) :  getCoordinates(_startIndex))
	   << std::endl;
    ss << "Closed List:";
    for(unsigned i = 0; i < _closedList.size(); ++i)
    {
		ss << " " << getCoordinates(_closedList[i].getTerminus());
    }
    ss << std::endl;
        
    ss << "Open List:";
    for(std::list<Route>::const_iterator it = _openList.begin(); it != _openList.end(); ++it)
    {
		ss << " " << getCoordinates(it -> getTerminus()) << ": (" << it -> getRouteWeight() << ")";
    }
    ss << std::endl;
    
        
    os << ss.str();

}

std::string Board::getCoordinates(unsigned index) const
{
    std::string ret;
    ret = ('A' + (index % gridWidth()));
    ret += ('1' + (index / gridWidth())); 
    return ret;   
}



bool Board::next(std::ostream& os)
{

	if(_openList.empty())
	{
		os << std::endl << "No Path between " << getCoordinates(_startIndex) << " and " << getCoordinates(_endIndex) << std::endl;
		return true;
	}

	//
	sortOpenNodes();
	Route rt = *_openList.begin();
	_openList.erase(_openList.begin());
	_closedList.push_back(rt);
	addNeighboursToOpenList(rt);
	if(rt.getTerminus() == _endIndex)
	{

		os << std::endl << "Best Path: ";
		for(unsigned i = 0; i < rt.steps().size(); ++i)
		{
			os << " " << getCoordinates(rt.steps()[i]);
		}
		os << " " << getCoordinates(rt.getTerminus()) << " " << ". Weight: " << rt.getRouteWeight() << std::endl;

		return true;
	}


    
    return false;
    
}
