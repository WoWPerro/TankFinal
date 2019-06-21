#include "Gif.h"

Gif::Gif()
{
}

void Gif::Init(Platform *platform)
{
	this->platform = platform;
}

void Gif::SetPositionX(int positionX)
{
	this->positionX = positionX;
}

void Gif::SetPositionY(int positionY)
{
	this->positionY = positionY;
}

void Gif::SetGifVel(int gifVel)
{
	this->gifVel = gifVel;
}

void Gif::AddImage(std::string y)
{
	image = new Image();
	image->LoadImage(y);
	Images.push_back(image);
}

void Gif::SetLoop(bool x)
{
	if (x)
	{
		isLooping = true;
	}
	
	else
	{
		isLooping = false;
	}
}

void Gif::Update()
{

		platform->RenderImage(Images[i], positionX, positionY, 0);

		if (finish == false)
		{
			start++;
		}


		if (start >= gifVel)
		{
			if (finish == false)
			{
				i++;
			}


			if (i >= Images.size())
			{
				finish = true;
				if (isLooping)
				{
					i = 0;
					finish = false;
				}

				if (!isLooping)
				{
					i = (Images.size() - 1);
					finish = true;
				}
			}
				start = 0;
		}

}

void Gif::Draw()
{
	
}

int Gif::GetPositionX()
{
	return positionX;
}

int Gif::GetPositionY()
{
	return positionY;
}

Gif::~Gif()
{
}
