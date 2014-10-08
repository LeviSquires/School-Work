var IGEFrame = function(xPos, yPos, width, height)
{
	var _x = xPos;
	var _y = yPos;
	var _width = width;
	var _height = height;
	
	this.getx = function()
	{
		return _x;
	};
	this.gety = function()
	{
		return _y;
	};
	this.getWidth = function()
	{
		return _width;
	};
	this.getHeight = function()
	{
		return _height;
	};
};
var animationRange = function(rangeName, start, end)
{
	var rangeName;
	var start;.
	var end;
	var currentFrame;
};

var InGameObject = function(file, sx, sy, sw, sh, dx, dy, dw, dh)
{
	var _x = dx;
	var _y = dy;
	var _height = dh;
	var _width = dw;
	var _img = new Image();
	_img.src = file;
	var _frames = new Array();
	_frames.push(new IGEFrame(sx, sy, sw, sh));
	var _currentFrame = 0;
	
	
	
	
	var _vx = 0;
	var _vy = 0;
	var _accelx = 0;
	var _accely = 0;
	
	this.getx = function()
	{
		return _x;
	};
	this.setx = function(v)
	{
		_x = v;
	};
	this.gety = function()
	{
		return _y;
	};
	this.sety = function(v)
	{
		_y = v;
	};
	this.getWidth = function()
	{
		return _width;
	};
	this.getHeight = function()
	{
		return _height;
	};
	
	this.nextFrame = function()
	{
		++_currentFrame;
		if(_currentRange == _ranges[i].getName())
		{
			
		};
	};
	this.addFrame = function(xPos, yPos, width, height)
	{
			_frames.push(new IGEFrame(xPos, yPos, width, height));
	};
	this.getvx = function()
	{
		return _vx;
	};
	this.setvx = function(v)
	{
		_vx = v;
	};
	this.getvy = function()
	{
		return _vy;
	};
	this.setvy = function(v)
	{
		_vy = v;
	};
	this.getaccelx = function()
	{
		return _accelx;
	};
	this.setaccelx = function(v)
	{
		_accelx = v;
	};
	this.getaccely = function()
	{
		return _accely
	};
	this.setaccely = function(v)
	{
		_accely = v;
	};
	this.update = function()
	{
		_vx += _accelx;
		_x += _vx;
		_vy += _accely;
		_y += _vy;
		
		if(_vx === 0)
		{
			this.setRange("");
		};
		if(_vx < 0)
		{
			this.setRange("small mario walk left");
		};
		if(_vx > 0)
		{
			this.setRanger("small mario walk right");
		};
	};
	this.draw = function(c)
	{
		var currentFrame = 0;
		for(var i = 0; i < _ranges.length; ++i)
		{
			if(_currentRange
		
		
		c.drawImage(_img, _frames[_currentFrame].getx(), _frames[_currentFrame].gety(),
					_frames[_currentFrame].getWidth(), _frames[_currentFrame].getHeight(),
					_x, _y, _width, _height);
	
	};	
	
	
};