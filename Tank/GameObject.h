#pragma once
#include "Platform.h"
class GameObject
{
protected:
	float radius;
	float positionX, positionY;
public:
	virtual void Init(Platform *platform) = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
	float GetRadius();
	int GetPositionX();
	int GetPositionY();
};

