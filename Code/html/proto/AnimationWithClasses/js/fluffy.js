$(document).ready(function() {	
	const LEFT_ARROW = 37;
	const UP_ARROW = 38;
	const RIGHT_ARROW = 39;
	const DOWN_ARROW = 40;
	const SPEED = 5;
	const GRAVITY = 0.3;
	const FRICTION = 0.3;
	const FRAME_RATE = 1000 / 50;
	const SPACE = 32;
	const COR = 0.3;
		
	
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
		this.accely = 0;
		this.onGround = false;
		this.accelx = 0;
		
		this.setXAccel = function(acc)
		{
			this.accelx = acc;
		}
		this.setYAccel = function(acc)
		{
			this.accely = acc;
		}
		this.isOnGround = function()
		{
			return this.onGround;
		}
		this.setOnGround = function(val)
		{
			this.onGround = val;
		
			if(this.onGround == true)
			{
				this.setYAccel(0);
			}
			else
			{
				this.setYAccel(GRAVITY);
			}
		}
		
		this.width = function()
		{
			return this.img.width;
		};
		
		this.height = function()
		{
			return this.img.height;
		};
		
		this.setvx = function(vx)
		{
			this.vx = vx;
		};
		this.setvy = function(vy)
		{
			this.vy = vy;
		};
		
		this.setx = function(x)
		{
			this.x = x;
		};

		this.sety = function(y)
		{
			this.y = y;
		};
		
		this.getx = function()
		{
			return this.x;
		};
		this.getvy = function()
		{
			return this.vy;
		};
		
		this.gety = function()
		{
			return this.y;
		};
		
		this.draw = function(context)
		{
			context.drawImage(this.img, this.x, this.y);
		};
		
		this.update = function()
		{
			if(this.isOnGround())
			{
				this.vx += this.accelx;
				//if vx is close to 0 then set acceleration to 0
				if(Math.abs(this.vx) < FRICTION + 0.01)
				{
					this.accelX = 0;
					this.vx = 0;
				}
			}
			else
			{
				var drag = this.vx * this.vx * 0.01;
				if(this.vx < 0)
				{
					this.accelx = drag;
				}
				else
				{
					this.accelx = -drag;
				}
				this.vx += this.accelx;
			}
			this.x += this.vx;
			if(Math.abs(this.vx) < 0.01)
				{
					this.accelX = 0;
					this.vx = 0;
				}
			
			
			this.vy += this.accely;
			this.y += this.vy;			
		};
		
	};



	var fluffy = new Fluffy(0, 0, "images/fluffy.png");
	
	$(background).load(function() {
		context.drawImage(background, 0, 0);
	});
	
	
	$(fluffy.img).load(function() {
		
		fluffy.x = (canvas.width() - fluffy.img.width) / 2;
		fluffy.y = (canvas.height() - fluffy.img.height) / 2;
		
		fluffy.draw(context);
	});
	
	
	animate();
	
	function animate()
	{
		setInterval(draw, FRAME_RATE);
	};
	
	function draw()
	{
	
		fluffy.update();
		
		

		if(fluffy.getx() < 0)
		{
			fluffy.setx(0);
			fluffy.setvx(0);
		}
		
		if(fluffy.getx() > (canvas.width() - fluffy.width()))
		{
			fluffy.setx(canvas.width() - fluffy.width());
			fluffy.setvx(0);
		}
		
		/*if(fluffy.gety() < 0)
		{
			fluffy.sety(0);
			fluffy.setvy(0);
		}
		*/
		if(fluffy.gety() >= (canvas.height() - fluffy.height() -1))
		{
			fluffy.sety(canvas.height() - fluffy.height());
			fluffy.setOnGround(true);
			fluffy.setvy(fluffy.getvy() * -COR);
			
			
			
		}
		else
		{
			fluffy.setOnGround(false);
			if(Math.abs(fluffy.gety() - (canvas.height() - fluffy.height())) < 2)
			{
				fluffy.sety(canvas.height() - fluffy.height());
			}
		}
		
		
		//console.log("Fluffy x: " + fluffyX + ". Fluffy Y: " + fluffyY);
		
		
		
		context.clearRect(0, 0, canvas.width(), canvas.height());
		context.drawImage(background, 0, 0);
		fluffy.draw(context);
		
		
		
	};
	
	function keyDownHandler(event)
	{
		switch(event.keyCode)
		{
			case LEFT_ARROW:
				fluffy.setvx(-SPEED);
				break;
			case UP_ARROW:
				//fluffy.setvy(-SPEED);
				break;
			case RIGHT_ARROW:
				fluffy.setvx(SPEED);
				break;
			case DOWN_ARROW:
				//fluffy.setvy(SPEED);
				break;
			case SPACE:
				if(fluffy.onGround)
				{
					if(event.ctrlKey == false)
					{
						fluffy.setvy(-14);
					}
					else
					{
						fluffy.setvy(-30);
					}
				}
				break;
				
		}
	};
	
	function keyUpHandler(event)
	{
		switch(event.keyCode)
		{
			case LEFT_ARROW: //fall-through
				if(fluffy.isOnGround())
				{
					fluffy.setXAccel(FRICTION);
				}
				
				break;
			case RIGHT_ARROW:
				if(fluffy.isOnGround())
				{
					fluffy.setXAccel(-FRICTION);
				}
				
				break;
			
			case UP_ARROW: //fall-through
			case DOWN_ARROW:
				//fluffy.setvy(0);
				break;
		}
	};
});
