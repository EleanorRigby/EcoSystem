//#include "Headers.h"

class Position_XY
{
public:
	int x;
	int y;

	Position_XY (int pX, int pY)
	{
		x = pX;
		y = pY;
	}

	Position_XY * Position_Locater (int pDim_X, int pDim_Y) const;

private:
	Position_XY () {}
};

/* POSITION LOCATER */
Position_XY * Position_XY::Position_Locater (int pDim_X, int pDim_Y) const
{

	assert (x >= 0 && x < pDim_X && y >= 0 && y < pDim_Y);

	Position_XY * vPos = new Position_XY [8];
	
	int a;
	int b;
	int c;
	int d;
	
	//starts from the left side and continues clockwise
		
	if(x == 0)
		a = -1;
	else
		a = x-1;

		
	if(x == pDim_X-1)
		b = -1;
	else
		b  = x+1;
		
		
	if(y == 0)
		c = -1;
	else
		c = y-1;

		
	if(y == pDim_Y-1)
		d = -1;
	else
		d  = y+1;
		

	vPos[3].x = (a);
	vPos[3].y = (c);
			

    vPos[4].x = (a);
	vPos[4].y = (y);
	
	vPos[5].x = (a);
	vPos[5].y = (d);
			
	vPos[7].x = (b);
	vPos[7].y = (d);
		
	vPos[0].x = (b);
	vPos[0].y = (y);
			
	vPos[1].x = (b);
	vPos[1].y = (c);

	vPos[2].x = (x);
	vPos[2].y = (c);
			
	vPos[6].x = (x);
	vPos[6].y = (d);

	return vPos;
}
