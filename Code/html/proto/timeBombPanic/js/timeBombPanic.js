$(document).ready(function() {
  const LEFT_ARROW = 37;
  const UP_ARROW = 38;
  const RIGHT_ARROW = 39;
  const DOWN_ARROW = 40;
  const FRAME_RATE = 20;
  const SPEED = 7;  
  const TILE_WIDTH = 64;  
  const TILE_HEIGHT = 64;  
  const TIMER_HEIGHT = 49;
  const TIMER_WIDTH = 130;
  
  var canvas = $("#myCanvas");
  var context = canvas.get(0).getContext("2d");	      
        
  window.addEventListener("keydown", keyDownHandler, false);
  window.addEventListener("keyup", keyUpHandler, false);

  var backGround = new Image();
  backGround.src = "images/timeBombPanic.png";

  var blocks = new Array();
  createBlocks();
  
  var bombs = new Array();
  createBombs();
  
  var spike = new Spike("images/timeBombPanic.png", 192, 0, TILE_WIDTH, TILE_HEIGHT,
						5 * TILE_WIDTH, 3 * TILE_HEIGHT, TILE_WIDTH - 8, TILE_HEIGHT - 8);
  
  var gt = new GameTimer("images/timeBombPanic.png", 0, 64, TIMER_WIDTH, TIMER_HEIGHT, 
							(canvas.width - TIMER_WIDTH) / 2, (TILE_HEIGHT - TIMER_HEIGHT) / 2,
							TIMER_WIDTH, TIMER_HEIGHT);
  
	




  
  animate();
  
  function animate()
  {
    setInterval(draw, FRAME_RATE);
  };
  
  function checkGameOver()
  {
	checkForLoss();
	checkForWin();
  }
  function checkForWin()
	{
		for(var i= 0; i < bombs.length; ++i)
		{
			if(bombs[i] != null)
			return false;
		}

	}
  
  function checkForLoss()
  {
	if(gt.getTimeRemaining() != 0)
	{
		return false;
	}
	return true;
}
  
  function draw()
  {
	spike.update();
	
	
	for(var i = 0; i < blocks.length; ++i)
	{
		Collision.block(spike, blocks[i]);
	}
	for(var i= 0; i < bombs.length; ++i)
    {
		if(bombs[i] != null)
		{
			if(Collision.block(spike, bombs[i]) == true)
			{
				bombs[i].setAlpha(0);
				bombs[i] = null;
			}
		}	
    }
    
	checkGameOver();
	
	
	
	
	
	context.clearRect(0, 0, canvas.width(), canvas.height());
    drawBackgrounds(context);
    for(var i= 0; i < blocks.length; ++i)
    {
      blocks[i].draw(context);
    } 
	for(var i= 0; i < bombs.length; ++i)
    {
		if(bombs[i] != null)
		{	
			bombs[i].draw(context);
		}
    } 
	spike.draw(context);
	gt.draw(context);
  };
  
  
  
function keyDownHandler(event)
{
console.log(event);
switch(event.keyCode)
{
case LEFT_ARROW:
spike.setvx(-SPEED);
break;
case UP_ARROW:
spike.setvy(-SPEED);
break;
case RIGHT_ARROW:
spike.setvx(SPEED);
break;
case DOWN_ARROW:
spike.setvy(SPEED);
break;
}
};

function keyUpHandler(event)
{
//console.log(event);
switch(event.keyCode)
{
case LEFT_ARROW: //fall-through
case RIGHT_ARROW:
spike.setvx(0);
break;
case UP_ARROW: //fall-through
case DOWN_ARROW:
spike.setvy(0);
break;
}
};
  
  function createBombs()
  {
	const BOMB_HEIGHT = 36;
	const BOMB_WIDTH = 48;
	var xOffset = (TILE_WIDTH - BOMB_WIDTH) / 2 + 5;
	var yOffset = (TILE_HEIGHT - BOMB_HEIGHT) / 2 + 1;
	const BOMB_LOCATIONS = [
								[9 * TILE_WIDTH + xOffset, 2 * TILE_HEIGHT + yOffset],
								[2 * TILE_WIDTH + xOffset, 4 * TILE_HEIGHT + yOffset ],
								[6 * TILE_WIDTH + xOffset, 5 * TILE_HEIGHT + yOffset ],
								[4 * TILE_WIDTH + xOffset, 6 * TILE_HEIGHT + yOffset ],
								[7 * TILE_WIDTH + xOffset, 6 * TILE_HEIGHT + yOffset ],
							];
	for(var i = 0; i < BOMB_LOCATIONS.length; ++i)
	{	
		bombs.push(new Bomb("images/timeBombPanic.png", 
						256, 0, BOMB_WIDTH, BOMB_HEIGHT, 
						BOMB_LOCATIONS[i] [0], BOMB_LOCATIONS[i] [1], 
						BOMB_WIDTH, BOMB_HEIGHT));
	};
	};

  function   createBlocks()
  {
    const BLOCK_LOCATIONS = [
                              [0 * TILE_WIDTH, 0 * TILE_HEIGHT],
                              [1 * TILE_WIDTH, 0 * TILE_HEIGHT],
                              [2 * TILE_WIDTH, 0 * TILE_HEIGHT],
                              [3 * TILE_WIDTH, 0 * TILE_HEIGHT],
                              [4 * TILE_WIDTH, 0 * TILE_HEIGHT],
                              [5 * TILE_WIDTH, 0 * TILE_HEIGHT],
                              [6 * TILE_WIDTH, 0 * TILE_HEIGHT],
                              [7 * TILE_WIDTH, 0 * TILE_HEIGHT],
                              [8 * TILE_WIDTH, 0 * TILE_HEIGHT],
                              [9 * TILE_WIDTH, 0 * TILE_HEIGHT],
                              [10 * TILE_WIDTH, 0 * TILE_HEIGHT],
                              
                              [0 * TILE_WIDTH, 1 * TILE_HEIGHT],
                              [10 * TILE_WIDTH, 1 * TILE_HEIGHT],
                              [0 * TILE_WIDTH, 2 * TILE_HEIGHT],
                              [10 * TILE_WIDTH, 2 * TILE_HEIGHT],
                              [0 * TILE_WIDTH, 3 * TILE_HEIGHT],
                              [10 * TILE_WIDTH, 3 * TILE_HEIGHT],
                              [0 * TILE_WIDTH, 4 * TILE_HEIGHT],
                              [10 * TILE_WIDTH, 4 * TILE_HEIGHT],
                              [0 * TILE_WIDTH, 5 * TILE_HEIGHT],
                              [10 * TILE_WIDTH, 5 * TILE_HEIGHT],
                              [0 * TILE_WIDTH, 6 * TILE_HEIGHT],
                              [10 * TILE_WIDTH, 6 * TILE_HEIGHT],
                              [0 * TILE_WIDTH, 7 * TILE_HEIGHT],
                              [1 * TILE_WIDTH, 7 * TILE_HEIGHT],
                              [2 * TILE_WIDTH, 7 * TILE_HEIGHT],
                              [3 * TILE_WIDTH, 7 * TILE_HEIGHT],
                              [4 * TILE_WIDTH, 7 * TILE_HEIGHT],
                              [5 * TILE_WIDTH, 7 * TILE_HEIGHT],
                              [6 * TILE_WIDTH, 7 * TILE_HEIGHT],
                              [7 * TILE_WIDTH, 7 * TILE_HEIGHT],
                              [8 * TILE_WIDTH, 7 * TILE_HEIGHT],
                              [9 * TILE_WIDTH, 7 * TILE_HEIGHT],
                              [10 * TILE_WIDTH, 7 * TILE_HEIGHT]
                            ];
    for(var i = 0; i < BLOCK_LOCATIONS.length; ++i)
    {
      blocks.push(new Block("images/timeBombPanic.png", 
                  128, 0, TILE_WIDTH, TILE_HEIGHT, 
                  BLOCK_LOCATIONS[i][0], BLOCK_LOCATIONS[i][1], TILE_WIDTH, TILE_HEIGHT));
    }   
    
    const INNER_BLOCK_LOCATIONS = [
                                    [2 * TILE_WIDTH, 2 * TILE_HEIGHT],
                                    [3 * TILE_WIDTH, 2 * TILE_HEIGHT],
                                    [4 * TILE_WIDTH, 2 * TILE_HEIGHT],
                                    [6 * TILE_WIDTH, 2 * TILE_HEIGHT],
                                    [8 * TILE_WIDTH, 2 * TILE_HEIGHT],
                                    [3 * TILE_WIDTH, 3 * TILE_HEIGHT],
                                    [5 * TILE_WIDTH, 4 * TILE_HEIGHT],
                                    [8 * TILE_WIDTH, 4 * TILE_HEIGHT],
                                    [2 * TILE_WIDTH, 5 * TILE_HEIGHT],
                                    [4 * TILE_WIDTH, 5 * TILE_HEIGHT],
                                    [5 * TILE_WIDTH, 5 * TILE_HEIGHT],
                                    [7 * TILE_WIDTH, 5 * TILE_HEIGHT],
                                    [8 * TILE_WIDTH, 5 * TILE_HEIGHT],
                                    [6 * TILE_WIDTH, 6 * TILE_HEIGHT]
                                  ];

    for(var i = 0; i < INNER_BLOCK_LOCATIONS.length; ++i)
    {
      blocks.push(new Block("images/timeBombPanic.png", 
                  64, 0, TILE_WIDTH, TILE_HEIGHT, 
                  INNER_BLOCK_LOCATIONS[i][0], INNER_BLOCK_LOCATIONS[i][1], 
                  TILE_WIDTH, TILE_HEIGHT));
      
    }    
                    
  };

  function  drawBackgrounds(context)
  {
    const  BACKGROUND_LOCATIONS = [
                                    [1 * TILE_WIDTH, 1 * TILE_HEIGHT],
                                    [2 * TILE_WIDTH, 1 * TILE_HEIGHT],
                                    [3 * TILE_WIDTH, 1 * TILE_HEIGHT],
                                    [4 * TILE_WIDTH, 1 * TILE_HEIGHT],
                                    [5 * TILE_WIDTH, 1 * TILE_HEIGHT],
                                    [6 * TILE_WIDTH, 1 * TILE_HEIGHT],
                                    [7 * TILE_WIDTH, 1 * TILE_HEIGHT],
                                    [8 * TILE_WIDTH, 1 * TILE_HEIGHT],
                                    [9 * TILE_WIDTH, 1 * TILE_HEIGHT],
                                    [1 * TILE_WIDTH, 2 * TILE_HEIGHT],
                                    [5 * TILE_WIDTH, 2 * TILE_HEIGHT],
                                    [7 * TILE_WIDTH, 2 * TILE_HEIGHT],
                                    [9 * TILE_WIDTH, 2 * TILE_HEIGHT],
                                    [1 * TILE_WIDTH, 3 * TILE_HEIGHT],
                                    [2 * TILE_WIDTH, 3 * TILE_HEIGHT],
                                    [4 * TILE_WIDTH, 3 * TILE_HEIGHT],
                                    [5 * TILE_WIDTH, 3 * TILE_HEIGHT],
                                    [6 * TILE_WIDTH, 3 * TILE_HEIGHT],
                                    [7 * TILE_WIDTH, 3 * TILE_HEIGHT],
                                    [8 * TILE_WIDTH, 3 * TILE_HEIGHT],
                                    [9 * TILE_WIDTH, 3 * TILE_HEIGHT],
                                    [1 * TILE_WIDTH, 4 * TILE_HEIGHT],
                                    [2 * TILE_WIDTH, 4 * TILE_HEIGHT],
                                    [3 * TILE_WIDTH, 4 * TILE_HEIGHT],
                                    [4 * TILE_WIDTH, 4 * TILE_HEIGHT],
                                    [6 * TILE_WIDTH, 4 * TILE_HEIGHT],
                                    [7 * TILE_WIDTH, 4 * TILE_HEIGHT],
                                    [9 * TILE_WIDTH, 4 * TILE_HEIGHT],
                                    [1 * TILE_WIDTH, 5 * TILE_HEIGHT],
                                    [3 * TILE_WIDTH, 5 * TILE_HEIGHT],
                                    [6 * TILE_WIDTH, 5 * TILE_HEIGHT],
                                    [9 * TILE_WIDTH, 5 * TILE_HEIGHT],
                                    [1 * TILE_WIDTH, 6 * TILE_HEIGHT],
                                    [2 * TILE_WIDTH, 6 * TILE_HEIGHT],
                                    [3 * TILE_WIDTH, 6 * TILE_HEIGHT],
                                    [4 * TILE_WIDTH, 6 * TILE_HEIGHT],
                                    [5 * TILE_WIDTH, 6 * TILE_HEIGHT],
                                    [7 * TILE_WIDTH, 6 * TILE_HEIGHT],
                                    [8 * TILE_WIDTH, 6 * TILE_HEIGHT],
                                    [9 * TILE_WIDTH, 6 * TILE_HEIGHT]
                                  ];
    for(var i = 0; i < BACKGROUND_LOCATIONS.length; ++i)
    {
      context.drawImage(backGround, 0, 0, TILE_WIDTH, TILE_HEIGHT,
                        BACKGROUND_LOCATIONS[i][0], 
                        BACKGROUND_LOCATIONS[i][1],
                        TILE_WIDTH, TILE_HEIGHT);
    }                                 
  };

      

});