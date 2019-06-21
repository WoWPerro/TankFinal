#include "Bullet.h"
#include <math.h>
#include "Collision.h"

Bullet::Bullet(int x,int y,float a,float r,float v)
{
	positionX = x;
	positionY = y;
	angle = a;
	radius = r;
	velocity = v;
}

Bullet::~Bullet()
{
	delete image;
}

void Bullet::Init(Platform *platform)
{
	image = new Image();
	image->LoadImage("../Assets/Images/Bullet.png");
	this->platform = platform;
}

void Bullet::SetPool(std::list<GameObject *> *tilePool)
{
	this->tilePool = tilePool;
}

bool Bullet::Collision()
{
	/*for (auto object : *tilePool)
	{
		if (Collision::BoxCollision(positionX, positionY, image->GetWidth(), image->GetHeight(),
			object->GetPositionX(), object->GetPositionY(), 32, 32))
		{
			return true;
		}
	}*/
	return false;
}

void Bullet::Draw()
{
	platform->RenderImage(image, positionX, positionY, angle);
}

void Bullet::Hoaming(bool hoaming)
{
	if (hoaming)
	{
		this->hoaming = true;
	}
	
	else
	{
		this->hoaming = false;
	}
}

void Bullet::Follow(float x, float y)
{
	anglex = x - positionX;
	angley = y - positionY;
	distace = sqrtf((anglex*anglex) + (angley* angley));
	dirx = anglex / distace;
	diry = angley / distace;
}


void Bullet::Update()
{
	if (Collision())
	{
		positionX *= -1;
		positionY *= -1;
	}

	if (!hoaming)
	{
		positionX += (float)cos((angle * M_PI) / 180) * 12;
		positionY += (float)sin((angle * M_PI) / 180) * 12;
	}

	if (hoaming)
	{
		positionX += dirx * 12;
		positionY += diry * 12;
	}
}