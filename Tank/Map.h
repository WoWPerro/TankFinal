#pragma once
#include"Tile.h"
#include"Platform.h"
#include<vector>
#include<list>
#include"GameObject.h"
#include"Gif.h"

class Map : GameObject
{
private:

	std::vector<Tile*> tiles;
	Platform *platform;
	std::list<GameObject *> *tilePool;

public:
	Map();
	~Map();
	void Init(Platform *platform) override;
	void Draw() override;
	void Update() override;
	void SetPool(std::list<GameObject *> *tilePool);
	void MoveTile();
};

