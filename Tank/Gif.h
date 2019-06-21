#pragma once
#include "GameObject.h"
#include "Image.h"
#include <list>
#include <vector>

class Gif : GameObject
{

public:

	Gif();
	~Gif();

	std::vector <Image *> Images;

	void Draw() override;
	void Init(Platform *platform) override;
	void Update() override;
	void AddImage(std::string y);

	void SetPositionX(int positionX);
	void SetPositionY(int positionY);
	void SetGifVel(int gifVel);
	void SetLoop(bool x);

	int GetPositionX();
	int GetPositionY();
	int positionX = 0,
		positionY = 0;

	int gifVel = 30;
	int start = 0;

	bool isLooping = false;
	bool finish = false;

private:
		
	int i = 0;

	Platform *platform;
	Image *image;
};


