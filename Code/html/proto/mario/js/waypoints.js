var Path = function(start, end, keyCode)
{
	var _startIndex = start;
	var _endIndex = end;
	var _keyCode = keyCode;
	this.getStartIndex = function()
	{
		return _startIndex;
	};
	this.getEndIndex = function()
	{
		return _endIndex;
	};
	this.getKeyCode = function()
	{
		return _keyCode;
	};
	
}

var wayPoint = function(xPos, yPos)
{
	var _x = xPos;
	var _y = yPos;
	var _paths = new Array();
	this.getx = function()
	{
		return _x;
	};
	this.gety = function()
	{
		return _y;
	};
	this.addPath = function(p)
	{
		_paths.push(p);
	};
	this.getNextWayPoint = function(kc)
	{
		for(var i = 0; i < _paths.length; ++i)
		{
			if(_paths[i].getKeyCode() === kc)
			{
				return _paths[i].getEndIndex();
			}
		}
		return -1;
	};
};