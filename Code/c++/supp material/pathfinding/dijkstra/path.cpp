#include "path.h"

#include "cell.h"

Path::Path(unsigned origin, unsigned end, double weight) : _weight(weight), _origin(origin), _end(end)
{
}

unsigned Path::getOrigin() const
{
    return _origin;
}

unsigned Path::getEnd() const
{
    return _end;
}

double Path::getWeight() const
{
    return _weight;
}
