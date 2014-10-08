function collision()
{
	s_collisionSide = "";
};

collision.getcollisionSide = function()
{
	return s_collisionSide;
}

collision.block = function(ige1, ige2)
{
	var ige1hw = ige1.getWidth() / 2;
	var ige2hw = ige2.getWidth() / 2;
	var hOffset = Math.abs((ige1.getx() + ige1hw) - (ige2.getx() + ige2hw));
	if(hOffset > ige1hw + ige2hw)
	{
		//no vertical overlap
		s_collisionSide = "";
		return false;
	}
	var ige1hh = ige1.getHeight() / 2;
	var ige2hh = ige2.getHeight() / 2;
	var vOffset = Math.abs((ige1.gety() + ige1hh) - (ige2.gety() + ige2hh));
	if(vOffset > ige1hh + ige2hh)
	{
		//no horizontal overlap
		s_collisionSide = "";
		return false;
	}
	//if ige1.x + ige1.width >= ige2.x then we have collision on left side of block.
	//if ige1.x <= ige2.x + ige2.width we have collision on right.
	//if ige1.y + ige1.height >= ige2.y we have collision on top.
	//if ige1.y <= ige2.y + ige2.height we have collision on bottom.
	
	var xAdjust = 0;
	if(ige1.getvx() > 0)
	{
		//collision on left side of ige2
		collisionSide = "left";
		xAdjust = ige2.getx() - (ige1.getx() + ige1.getWidth());
	}
	
	
	if(ige1.getvx() < 0)
	{
		//collision on right side of ige2
		s_collisionSide = "right";
		xAdjust = (ige2.getx() + ige2.getWidth()) - ige1.getx();
	}
	
	var yAdjust = 0;
	if(ige1.getvy() > 0)
	{
		//collison on top
		s_collisionSide = "top";
		yAdjust = ige2.gety() - (ige1.gety() + ige1.getHeight());
	}
	if(ige1.getvy() < 0)
	{
		//collison on bottom
		s_collisionSide = "bottom";
		yAdjust = (ige2.gety() + ige2.getHeight()) - ige1.gety();
	}
	if(xAdjust && yAdjust)
	{
		//which direction takes precedence?
		if(Math.abs(xAdjust) < Math.abs(yAdjust))
		{
			yAdjust = 0;
		}
		else
		{
			xAdjust = 0;
		}
	
	}
	
	if(xAdjust !== 0)
	{
		ige1.setx(ige1.getx() + xAdjust);
	}
	if(yAdjust !== 0)
	{
		ige1.sety(ige1.gety() + yAdjust);
	}
		
	
	
	return true;
}