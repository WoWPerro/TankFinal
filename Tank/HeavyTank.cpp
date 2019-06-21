#include "HeavyTank.h"

#include "Collision.h"

#include <list>
#include<cstdlib>
#include<ctime>
#include "Bullet.h"

HeavyTank::HeavyTank()
{
}

void HeavyTank::Init(Platform *platform)
{
	image = new Image();
	image->LoadImage("../Assets/Images/HeavyTank.png");
	positionX = 300;
	positionY = 200;
	angle = 90;
	this->platform = platform;
	radius = 40;
	energy = 100;
}

void HeavyTank::SetPool(std::list<GameObject *> *bulletPoolEnemy, std::list<GameObject *> *tilePool,
	std::list<float *> *tankPosX, std::list<float *> *tankPosY)
{
	this->bulletPoolEnemy = bulletPoolEnemy;
	this->tilePool = tilePool;
	this->tankPosX = tankPosX;
	this->tankPosY = tankPosY;
}

void HeavyTank::getPool(std::list<GameObject *> *bulletPoolCheck)
{
	this->bulletPoolCheck = bulletPoolCheck;
}

void HeavyTank::SetPositionsTank(float x, float y)
{
	TankX = x;
	TankY = y;
}

void HeavyTank::Shoot()
{
	Bullet * newBullet = new Bullet((positionX + image->GetWidth() / 2) - 5.0f, (positionY + image->GetHeight() / 2) - 5.0f, angle, 1, 1);
	newBullet->Init(platform);
	newBullet->Follow(TankX, TankY);
	newBullet->Hoaming(true);

	bulletPoolEnemy->push_back(newBullet);
}



void HeavyTank::Update()
{

	Shoot();

	positionX += (float)cos((angle * M_PI) / 180) * 2.0;
	positionY += (float)sin((angle * M_PI) / 180) * 2.0;
	
	if (CollisionTile())
	{
		positionY -= (float)sin((angle * M_PI) / 180) * 20;
		positionX -= (float)cos((angle * M_PI) / 180) * 20;
		srand(time(0));		
		angle += rand()%360;
		if (angle < 20)
			angle += 10;
		
	}

	if (CollisionBullet())
	{
		energy -= 1;
	}
	
	angle = (int)angle % 360;
}

void HeavyTank:: Draw()
{
	if (energy > 0)
	{
		platform->RenderImage(image, positionX, positionY, angle);
	}
}

bool HeavyTank::CollisionTile()
{
	for (auto object : *tilePool)
	{
		if (Collision::BoxCollision(positionX, positionY, image->GetWidth(), image->GetHeight(),
			object->GetPositionX(), object->GetPositionY(), 32, 32))
		{
			return true;
		}
	}
	return false;
}

bool HeavyTank::CollisionBullet()
{
	for (auto object : *bulletPoolCheck)
	{
		if (Collision::BoxCollision(positionX, positionY, image->GetWidth(), image->GetHeight(),
			object->GetPositionX(), object->GetPositionY(), 32, 32))
		{
			return true;
		}
	}
	return false;
}



HeavyTank::~HeavyTank()
{
}