#if !defined(PATH_H)
#define PATH_H

class Cell;

class Path
{
public:
    Path(unsigned origin, unsigned end, double weight);    
    unsigned getOrigin() const;
    unsigned getEnd() const;
    double getWeight() const;
private:
    double _weight;
    unsigned _origin;
    unsigned _end;    
    
};

#endif
