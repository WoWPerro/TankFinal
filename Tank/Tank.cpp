#include "Tank.h"
#include "Platform.h"
#include "Bullet.h"
#include <math.h>
#include "Collision.h"



Tank::Tank()
{
}

Tank::~Tank()
{
}

void Tank::SetPool(std::list<GameObject *> *bulletPool, std::list<GameObject *> *tilePool, 
	std::list<float *> *positionsTankX, std::list<float *> *positionsTankY)
{
	this->bulletPool = bulletPool;
	this->tilePool = tilePool;
	this->positionsTankX = positionsTankX;
	this->positionsTankY = positionsTankY;
}

void Tank::getPool(std::list<GameObject *> *bulletPoolCheck)
{
	this->bulletPoolCheck = bulletPoolCheck;
}

void Tank::Init(Platform *platform)
{
	image = new Image();
	image->LoadImage("../Assets/Images/TankAsset.png");
	positionX = 100;
	positionY = 100;
	angle = 0;
	radius = image->GetHeight() / 2;
	this->platform = platform;
	energy = 100;
	tileCollision = false;
}

void Tank::Draw()
{
	if (energy != 0)
	{
		platform->RenderImage(image, positionX , positionY , angle);
		#ifdef _DEBUG_TANK_
			platform->DrawRect(positionX , positionY , image->GetWidth(), image->GetHeight());
		#endif
	}
}

bool Tank::CollisionTile()
{
	for (auto object : *tilePool)
	{
		if (Collision::BoxCollision(positionX, positionY,image->GetWidth(),image->GetHeight(),
			object->GetPositionX(), object->GetPositionY(), 32,32))
		{
			return true;
		}
	}
	return false;
}

bool Tank::CollisionBullet()
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

void Tank::Input(std::vector<int> * keyUps, std::vector<int> * keyDowns)
{

	for (auto keyInput : *keyUps)
	{
		if (keyInput == 1073741904)
		{
			Izquierda = false;
		}

		if (keyInput == 1073741903)
		{
			Derecha = false;
		}

		if (keyInput == 32)
		{
			Spacebar = true;
		}

		if (keyInput == 1073741906)
		{
			Arriba = false;
		}

		if (keyInput == 1073741905)
		{
			Abajo = false;
		}
	}

	for (auto keyInput : *keyDowns)
	{
		if (keyInput == 1073741904)
		{
			Izquierda = true;
		}

		if (keyInput == 1073741903)
		{
			Derecha = true;
		}

		if (keyInput == 32)
		{
			Spacebar = false;
		}

		if (keyInput == 1073741906)
		{
			Arriba = true;
		}

		if (keyInput == 1073741905)
		{
			Abajo = true;
		}
	}

}


void Tank::Update()
{
	if (Derecha)
	{
		angle -= 5;
	}

	if (Izquierda)
	{
		angle += 5;
	}

	if (Spacebar)
	{
		Bullet * newBullet = new Bullet((positionX + image->GetWidth() / 2) - 5.0f, (positionY + image->GetHeight() / 2) - 5.0f, angle, 1, 1);
		newBullet->Init(platform);

		bulletPool->push_back(newBullet);
	}

	if (Arriba)
	{
		positionX -= (float)cos((angle * M_PI) / 180) * 5;
		if (CollisionTile())
		{
			positionX += (float)cos((angle * M_PI) / 180) * 7;
			return;
		}

		positionY -= (float)sin((angle * M_PI) / 180) * 5;
		if (CollisionTile())
		{
			positionY += (float)sin((angle * M_PI) / 180) * 7;
			return;
		}
	}

	if (Abajo)
	{
		positionX += (float)cos((angle * M_PI) / 180) * 5;

		if (CollisionTile())
		{
			positionX -= (float)cos((angle * M_PI) / 180) * 7;
			return;
		}

		positionY += (float)sin((angle * M_PI) / 180) * 5;

		if (CollisionTile())
		{
			positionY -= (float)sin((angle * M_PI) / 180) * 7;
			return;
		}
	}

	*posX = positionX;
	positionsTankX->push_back(posX);
	if (positionsTankX->size() > 100)
	{
		positionsTankX->pop_front();
	}

	*posY = positionY;

	positionsTankY->push_back(posY);
	if (positionsTankY->size() > 100)
	{
		positionsTankX->pop_front();
	}
	
	//delete posX;
	//delete posY;
}


float Tank::GetRadius()
{
	return radius;
}

float Tank::GetAngle()
{
	return angle;
}

int Tank::GetPositionX() 
{
	return positionX;
}

int Tank::GetPositionY() 
{
	return positionY;
}