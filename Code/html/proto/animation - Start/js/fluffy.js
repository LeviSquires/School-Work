$(document).ready(function() {	
	const LEFT_ARROW = 37;
	const UP_ARROW = 38;
	const RIGHT_ARROW = 39;
	const DOWN_ARROW = 40;
	const SPEED = 5;
	
	var canvas = $("#myCanvas");
	var context = canvas.get(0).getContext("2d");
	
	
	
	window.addEventListener("keydown", keyDownHandler, false);
	window.addEventListener("keyup", keyUpHandler, false);
	
	var background = new Image();
	background.src = "images/background.png";
	
	var Fluffy = function(x, y, src)
	{
		this.x = x;
		this.y = y;
		this.img = new Image();
		this.img.src = src;
		this.vx = 0;
		this.vy = 0;
		
		this.width = function()
		{
			return this.img.width;
		}
		this.height = function()
		{
			return this.img.height;
		}
		this.draw = function(context)
		{
			context.drawImage(this.img, this.x, this.y);
		};
		this.setx = function(x)
		{
			this.x = x;
		}
		this.sety = function(y)
		{
			this.y = y;
		}
		this.setvx = function(vx)
		{
			this.vx = vx;
		}
		this.setvy = function(vy)
		{
			this.vy = vy;
		}
		this.getx = function()
		{
			return this.x;
		}
		this.gety = function()
		{
			return this.y;
		}
			
		this.update = function()
		{
			this.x += Math.floor(Math.random() * 11) - 6;
			this.y += Math.floor(Math.random() * 11) - 6;
		};
	};
	var fluffies = new Array();
	fluffies[0] = new fluffy(250, 175, "images/fluffy.png");
	fluffies[1] = new fluffy(250, 175, "images/fluffy.png");
	//var fluffy = new Fluffy(0, 0, "images/fluffy.png");
	
	$(background).load(function() {
		context.drawImage(background, 0, 0);
	});
	
	/*
	$(fluffy.img).load(function() {
		fluffy.x = (canvas.width() - fluffy.img.width) / 2;
		fluffy.y = (canvas.height() - fluffy.img.height) / 2;
		fluffy.draw(context);
		
	});
	*/
	function animate()
	{
		setInterval (draw, 20);
	};
	function draw()
	{
		//fluffy.update();
		
		for(var i = 0; i < fluffies.length; ++i)
		{
			fluffies[i].update();
			
			if(fluffies[i].getx() < 0)
			{
				fluffies[i].setx(0);
				fluffies[i].setvx(0);
			}
			if(fluffies[i].getx() > (canvas.width() - fluffy.width()))
			{
				fluffies[i].setx(canvas.width() - fluffy.width());
				fluffies[i].setvx(0);
			}
			if(fluffies[i].gety() < 0)
			{
				fluffies[i].sety(0);
			}
			if(fluffies[i].gety() > (canvas.height() - fluffy.height()))
			{
				fluffies[i].sety(canvas.height() - fluffy.height());
			}
			context.clearRect(0, 0, canvas.width(), canvas.height());
			context.drawImage(background, 0, 0);
			for(var i =0; i < fluffies.length; ++i)
			{
				
			}
				
			fluffy.draw(context);
	};
	function keyDownHandler(event)
	{
		switch(event.keyCode)
		{
			case LEFT_ARROW:
				fluffy.vx = -SPEED;
				break;
			case UP_ARROW:
				fluffy.vy = -SPEED;
				break;
			case RIGHT_ARROW:
				fluffy.vx = SPEED;
				break;
			case DOWN_ARROW:
				fluffy.vy = SPEED;
				break;
		}
	};
	function keyUpHandler(event)
	{
		switch(event.keyCode)
		{
			case LEFT_ARROW://fall through
			case RIGHT_ARROW:
				fluffy.vx = 0;
				break;
			case UP_ARROW://fall through
			case DOWN_ARROW:
				fluffy.vy = 0;
				break;
		}
		
	
	};
	animate();
});
