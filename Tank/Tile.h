#pragma once
#include "GameObject.h"

class Tile : public GameObject
{
private:

	Image *image;
	Platform *platform;

public:
	Tile(int positionX, int positionY, float radius);
	void Init(Platform *platform) override;
	void Draw() override;
	void Update() override;
	~Tile();
};

