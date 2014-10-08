#if !defined(ROUTE_H__)
#define ROUTE_H__

class Route
{
public:
	Route(unsigned terminus) : _terminus(terminus), _weight(0)
	{
	}

	Route(const Route& rt, unsigned newStep, double stepWeight) :   _terminus(newStep), _steps(rt._steps), _weight(rt._weight + stepWeight)
	{
		_steps.push_back(rt._terminus);
	}

	double getRouteWeight() const 
	{
		return _weight;
	}
	unsigned getTerminus() const
	{
		return _terminus;
	}
	const std::vector<unsigned>& steps() const
	{
		return _steps;
	}

private:
	unsigned _terminus;
	std::vector<unsigned> _steps;
	double _weight;
};





#endif
