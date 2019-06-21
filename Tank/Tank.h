#pragma once
#include "GameObject.h"
#include "Image.h"
#include <list>

class Tank:GameObject
{
public:

	Tank();
	~Tank();
	void Draw() override;
	void Init(Platform *platform) override;

	void Input(std::vector<int> * keyUps, std::vector<int> * keyDowns);

	void Update() override;

	void SetPool(std::list<GameObject *> *bulletPool, std::list<GameObject *> *tilePool, 
		std::list<float *> *positionsTankX, std::list<float *> *positionsTankY);

	bool CollisionTile();
	bool CollisionBullet();
	void getPool(std::list<GameObject *> *bulletPoolCheck);

	float GetRadius();
	float GetAngle();
	int GetPositionX();
	int GetPositionY();


private:

	float angle;
	float positionX, positionY;
	Image *image;
	Platform *platform;
	float radius;
	int energy;
	float posX1;
	float posY1;
	float *posY = &posX1;
	float *posX = &posY1;
	bool Izquierda = false, 
		Derecha = false,
		Arriba = false,
		Abajo = false,
		Spacebar = false;

	bool tileCollision;
	std::list<GameObject *> *bulletPool;
	std::list<GameObject *> *bulletPoolCheck;
	std::list<GameObject *> *tilePool;
	std::list<float *> *positionsTankX;
	std::list<float *> *positionsTankY;

};

