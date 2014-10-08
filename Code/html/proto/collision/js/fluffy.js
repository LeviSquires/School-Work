$(document).ready(function() {	
	const LEFT_ARROW = 37;
	const UP_ARROW = 38;
	const RIGHT_ARROW = 39;
	const DOWN_ARROW = 40;
	const SPEED = 5;
	const FRAME_RATE = 1000 / 50;

	
	var canvas = $("#myCanvas");
	var context = canvas.get(0).getContext("2d");
	
	window.addEventListener("keydown", keyDownHandler, false);
	window.addEventListener("keyup", keyUpHandler, false);
		
	var blk = new InGameEntity("images/fluffy.png", 0, 0, 64, 64, 352, 199);
	var fluffy = new InGameEntity("images/fluffy.png", 64, 0, 64, 64, 250, 175);

	
	
	animate();
	
	function animate()
	{
		setInterval(draw, FRAME_RATE);
	};
	
	function draw()
	{
	

		fluffy.update();
		
		if(collision.block(fluffy, blk) == true)
		{
			switch(collision.getcollsionSide())
			{
				case "left":
				console.log("collision on left");
				break;
				case "right":
				console.log("collision on right");
				break;
				case "top":
				console.log("collision on top");
				break;
				case "bottom":
				console.log("collision on bottom");
				break;
			}
		}
		context.clearRect(0, 0, canvas.width(), canvas.height());
		blk.draw(context);
		fluffy.draw(context);

		
	};
	
	function keyDownHandler(event)
	{
	  console.log(event);
		switch(event.keyCode)
		{
			case LEFT_ARROW:
			fluffy.setvx(-SPEED);
				
				break;
			case UP_ARROW:
			fluffy.setvy(-SPEED);
				
				break;
			case RIGHT_ARROW:
			fluffy.setvx(SPEED);
			
				break;
			case DOWN_ARROW:
			fluffy.setvy(SPEED);
						
					break;
		}
	};
	
	function keyUpHandler(event)
	{
	  console.log(event);
		switch(event.keyCode)
		{
			case LEFT_ARROW: //fall-through
			case RIGHT_ARROW:
			fluffy.setvx(0);
				break;
			
			case UP_ARROW: //fall-through
			case DOWN_ARROW:
			fluffy.setvy(0);
				break;
		}
	};
});
