#pragma once
#include "GameObject.h"
#include <list>
#include <math.h>
#include "Collision.h"

class Bullet : public GameObject
{
public:
	void Init(Platform *platform) override;
	void Draw() override;
	bool Collision();
	void SetPool(std::list<GameObject *> *tilePool);
	Bullet(int x, int y, float a, float r, float v);
	~Bullet();
	void Update() override;
	bool hoaming = false;
	void Hoaming(bool hoaming);

	void Follow(float x, float y);

private:
	float angle;
	Image *image;
	Platform *platform;
	float velocity;
	float dirx = 0;
	float diry = 0;
	float anglex = 0;
	float angley = 0;
	float distace = 0;

	
	std::list<GameObject *> *tilePool;
	std::list<GameObject *> *tankPool;
};
