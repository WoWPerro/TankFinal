#pragma once
#include "Image.h"
#include "Platform.h"
#include "GameObject.h"
#include <list>
#include "Bullet.h"

class HeavyTank : public GameObject
{
private:
	float angle;
	Image *image;
	Platform *platform;
	std::list<GameObject *> *bulletPoolEnemy;
	std::list<GameObject *> *tilePool;
	std::list<GameObject *> *bulletPoolCheck;
	std::list<float *> *tankPosX;
	std::list<float *> *tankPosY;

public:
	int energy = 100;
	HeavyTank();
	void Init(Platform *platform) override;
	void Update() override;
	void Draw() override;
	~HeavyTank();

	bool CollisionTile();
	bool CollisionBullet();
	void Shoot();

	float TankX = 0;
	float TankY = 0;
	void SetPositionsTank(float x, float y);

	void SetPool(std::list<GameObject *> *bulletPool, std::list<GameObject *> *tilePool, 
		std::list<float *> *tankPosX, std::list<float *> *tankPosY);
	void getPool(std::list<GameObject *> *bulletPoolCheck);
};

