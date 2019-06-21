#pragma once
class Collision
{
public:

	static bool CircleCollision(float r1, float r2, int x1, int y1, int x2, int y2);
	static bool BoxCollision(int x1, int y1, int w1, int h1, int x2, int y2,int w2, int h2);
	static bool BoxCollisionX(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
	
};

