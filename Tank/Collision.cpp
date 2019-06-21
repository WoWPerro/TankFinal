#include "Collision.h"
#include<math.h>

bool Collision::CircleCollision(float r1, float r2, int x1, int y1, int x2, int y2)
{
	float d = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (d >= r1 + r2)
		return false;
	else
		return true;
}

bool Collision::BoxCollisionX(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if ((x2 > x1 && x2 < x1 + w1) || (x2 + w2 > x1 && x2 + w2 < x1 + w1))
	{

			return true;

	}
	return false;
}

bool Collision::BoxCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if ((x2 > x1 && x2 < x1 + w1) || (x2 + w2 > x1 && x2 + w2 <x1 + w1))
	{
		if ((y2 > y1 && y2 < y1 + h1) || (y2 + h2 > y1 && y2 + h2 < y1 + h1))
		{
			return true;
		}
	}
	return false;

}


