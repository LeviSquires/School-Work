#include "cell.h"
#include <iostream>
#include "board.h"



void Cell::addPath(const Path& p)
{
    _paths.push_back(p);
//std::cout << "Path added with weight: " << p.getWeight() << std::endl;    
}

bool Cell::isStart() const
{
    return _start;
}

bool Cell::isEnd() const
{
    return _end;
}

bool Cell::isBlock() const
{
    return _block;
}

void Cell::setBlock()
{
    _block = true;
}

void Cell::setStart()
{
    _start = true;
    _weight = 0.0;
}
    
void Cell::setEnd()
{
    _end = true;
    _weight = 0.0;    
}


bool Cell::canMoveRight() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() + 1 == _paths[i].getEnd())
        {
            return true;
        }
    }
    return false;
}

bool Cell::canMoveLeft() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() - 1 == _paths[i].getEnd())
        {
            return true;
        }
    }
    return false;
}


bool Cell::canMoveDown() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() + Board::gridWidth() == _paths[i].getEnd())
        {
            return true;
        }
    }
    return false;
}
bool Cell::canMoveDownRight() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() + Board::gridWidth() + 1 == _paths[i].getEnd())
        {
            return true;
        }
    }
    return false;
}
bool Cell::canMoveDownLeft() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() + (Board::gridWidth() - 1) == _paths[i].getEnd())
        {
            return true;
        }
    }
    return false;
    
}



bool Cell::canMoveUp() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() - Board::gridWidth() == _paths[i].getEnd())
        {
            return true;
        }
    }
    return false;
}
bool Cell::canMoveUpRight() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() - (Board::gridWidth() - 1) == _paths[i].getEnd())
        {
            return true;
        }
    }
    return false;
}
bool Cell::canMoveUpLeft() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() - (Board::gridWidth() + 1) == _paths[i].getEnd())
        {
            return true;
        }
    }
    return false;
    
}


double Cell::getCostRight() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() + 1 == _paths[i].getEnd())
        {
            return _paths[i].getWeight();
        }
    }    
    return 0;
}

void Cell::calcWeight(double cost)
{
    _weight += cost;
}    


double Cell::getCostDown() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() + Board::gridWidth() == _paths[i].getEnd())
        {
            return _paths[i].getWeight();
        }
    }    
    return 0;
}

double Cell::getCostDownRight() const    
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() + Board::gridWidth() + 1 == _paths[i].getEnd())
        {
            return _paths[i].getWeight();
        }
    }    
    return 0;
}
double Cell::getCostDownLeft() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() + (Board::gridWidth() - 1) == _paths[i].getEnd())
        {
            return _paths[i].getWeight();
        }
    }    
    return 0;
}


double Cell::getCostLeft() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() - 1 == _paths[i].getEnd())
        {
            return _paths[i].getWeight();
        }
    }    
    return 0;
}



double Cell::getCostUp() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() - Board::gridWidth() == _paths[i].getEnd())
        {
            return _paths[i].getWeight();
        }
    }    
    return 0;
}

double Cell::getCostUpRight() const    
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() - (Board::gridWidth() - 1) == _paths[i].getEnd())
        {
            return _paths[i].getWeight();
        }
    }    
    return 0;
}

double Cell::getCostUpLeft() const
{
    for(unsigned i = 0; i < _paths.size(); ++i)
    {
        if(_paths[i].getOrigin() - (Board::gridWidth() + 1) == _paths[i].getEnd())
        {
            return _paths[i].getWeight();
        }
    }    
    return 0;
}

