var InGameEntity = function(file, sx, sy, swidth, sheight, dx, dy)
{
    var _x = dx; //destination x
    var _y = dy; //destination y
    var _width = swidth; //width of source and destination: no scaling
    var _height = sheight; //height of source and destination
    var _sx = sx; //Source x
    var _sy = sy; //source
    var _img = new Image();
    _img.src = file;
    
    
    var _vx = 0;
    var _vy = 0;
    
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
    
    this.update = function()
    {
      _x += _vx;
      _y += _vy;
    };
    
    this.draw = function(c)
    {
      c.drawImage(_img, _sx, _sy, _width, _height, _x, _y, _width, _height);
    };
};
	