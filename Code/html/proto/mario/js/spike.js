$(document).ready(function() {	
	const KEY_LEFT = 37;
	const KEY_UP = 38;
	const KEY_RIGHT = 39;
	const KEY_DOWN = 40;
	const FRAME_RATE = 1000 / 50;
	const VELOCITY = 7;
	const SPIKE_WIDTH = 64;
	const SPIKE_HEIGHT = 64;
	const BG_HEIGHT = 1922;
	const BG_WIDTH = 2561;
	
	var canvas = $("#myCanvas");
	var context = canvas.get(0).getContext("2d");
	
	var innerLeft = canvas.width() *0.25;
	var innerRight = canvas.width() * 0.75;
	var innerTop = canvas.height() * 0.25;
	var innerBottom = canvas.height() * 0.75;
	

	window.addEventListener("keydown", keyDownHandler, false);
	window.addEventListener("keyup", keyUpHandler, false);
	
	
	
	function keyDownHandler(event)
	{
		switch(event.keyCode)
		{
			case KEY_LEFT:
				spike.setvx(-VELOCITY);

				break;
			case KEY_UP:
				spike.setvy(-VELOCITY);
			  
				break;
			case KEY_RIGHT:
				spike.setvx(VELOCITY);
			 
				break;
			case KEY_DOWN:
				spike.setvy(VELOCITY);
				
				break;
			default:
				break;
		}
	};
	
	function keyUpHandler(event)
	{
		switch(event.keyCode)
		{				
			case KEY_LEFT: //fall-through
			case KEY_RIGHT:
				spike.setvx(0);
				bg.setvx(0);
  	
  	
				break;
			case KEY_UP: //fall-through
			case KEY_DOWN:
				spike.setvy(0);
				bg.setvy(0);
  	
			
				break;	
			default:	
				
		}							
	};
	
	var inGameEntity = function(file, sx, sy, swidth, sheight, dx, dy)
	{
		var _x = dx; //destination x, declared as private.
		var _y = dy; //destination y.
		var _width = swidth; //width of source and destination.
		var _height = sheight; //height of source and destination.
		var _sx = sx; //source x.
		var _sy = sy; //source y.
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
	
	var bg = new inGameEntity("images/background.png", 0, SPIKE_HEIGHT, BG_WIDTH, BG_HEIGHT, 
															(canvas.width() - BG_WIDTH) / 2, 
															(canvas.height() - BG_HEIGHT) / 2);
	
	var spike = new inGameEntity("images/background.png", 0, 0, SPIKE_WIDTH, SPIKE_HEIGHT, (canvas.width() - SPIKE_WIDTH) / 2, (canvas.height() - SPIKE_HEIGHT) / 2);
	
	function animate()
	{
		setInterval(draw, FRAME_RATE);
	};
	
	animate();
	
	function draw()
	{
		spike.update();
		if(spike.getx() < innerLeft)
		{
			spike.setx(innerLeft);
			spike.setvx(0);
			bg.setvx(VELOCITY);
			innerRight = canvas.width() * 0.75;
		};
		if(spike.getx() > innerRight - spike.getWidth())
		{
			spike.setx(innerRight - spike.getWidth());
			spike.setvx(0);
			bg.setvx(-VELOCITY);
			innerLeft = canvas.width() * 0.25;
		};
		if(spike.gety() < innerTop)
		{
			spike.sety(innerTop);
			spike.setvy(0);
			bg.setvy(VELOCITY);
			innerBottom = canvas.height() * 0.75;
		};
		if(spike.gety() > innerBottom - spike.getHeight())
		{
			spike.sety(innerBottom - spike.getHeight());
			spike.setvy(0);
			bg.setvy(-VELOCITY);
			innerTop = canvas.height() * 0.25;
		};
		
		bg.update();// call bg update after all adjustments have been made.
		
		if(bg.getx() > 0)
		{
			bg.setx(0);
			bg.setvx(0);
			innerLeft = 0;
		};
		if(bg.getx() < canvas.width() - bg.getWidth())
		{
			bg.setx(canvas.width() - bg.getWidth());
			bg.setvx(0);
			innerRight = canvas.width();
		};
		if(bg.gety() > 0)
		{
			bg.sety(0);
			bg.setvy(0);
			innerTop = 0;
		};
		if(bg.gety() < canvas.height() - bg.getHeight())
		{
			bg.sety(canvas.height() - bg.getHeight());
			bg.setvy(0);
			innerBottom = canvas.height();
		};
	
		
		
		
		context.clearRect(0, 0, canvas.width(), canvas.height());
		bg.draw(context);
		spike.draw(context);
		context.strokeStyle = "rgb(255, 0, 0)";
		context.strokeRect(innerLeft, innerTop, innerRight - innerLeft, innerBottom - innerTop);
	};
	
		
	
	

});