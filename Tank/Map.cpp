#include "Map.h"
#include <vector>

Map::Map()
{
	float r = 2;
	int t = 0;
	for (int j = 0; j <= 60; j++)
	{
		tiles.push_back(new Tile(t, 0, r));
		tiles.push_back(new Tile(t, 1040, r));

		if (j < 33)
		{
			tiles.push_back(new Tile(0, t, r));
			tiles.push_back(new Tile(1888, t, r));
		}

		t += 32;

	}

	tiles.push_back(new Tile(192, 160, r));
	tiles.push_back(new Tile(192, 192, r));
	tiles.push_back(new Tile(192, 224, r));
	tiles.push_back(new Tile(192, 256, r));
	tiles.push_back(new Tile(192, 288, r));
	tiles.push_back(new Tile(192, 320, r));

	tiles.push_back(new Tile(192, 160 + (32 * 16), r));
	tiles.push_back(new Tile(192, 160 + (32 * 17), r));
	tiles.push_back(new Tile(192, 160 + (32 * 18), r));
	tiles.push_back(new Tile(192, 160 + (32 * 19), r));
	tiles.push_back(new Tile(192, 160 + (32 * 20), r));
	tiles.push_back(new Tile(192, 160 + (32 * 21), r));

	tiles.push_back(new Tile(800, 160, r));
	tiles.push_back(new Tile(800, 192, r));
	tiles.push_back(new Tile(800, 224, r));
	tiles.push_back(new Tile(800, 256, r));
	tiles.push_back(new Tile(800, 288, r));
	tiles.push_back(new Tile(800, 320, r));

	tiles.push_back(new Tile(800, 160 + (32 * 16), r));
	tiles.push_back(new Tile(800, 160 + (32 * 17), r));
	tiles.push_back(new Tile(800, 160 + (32 * 18), r));
	tiles.push_back(new Tile(800, 160 + (32 * 19), r));
	tiles.push_back(new Tile(800, 160 + (32 * 20), r));
	tiles.push_back(new Tile(800, 160 + (32 * 21), r));

	tiles.push_back(new Tile(416, 160, r));
	tiles.push_back(new Tile(416, 192, r));
	tiles.push_back(new Tile(416, 224, r));
	tiles.push_back(new Tile(416, 256, r));
	tiles.push_back(new Tile(416, 288, r));
	tiles.push_back(new Tile(416, 320, r));

	tiles.push_back(new Tile(416, 160 + (32 * 16), r));
	tiles.push_back(new Tile(416, 160 + (32 * 17), r));
	tiles.push_back(new Tile(416, 160 + (32 * 18), r));
	tiles.push_back(new Tile(416, 160 + (32 * 19), r));
	tiles.push_back(new Tile(416, 160 + (32 * 20), r));
	tiles.push_back(new Tile(416, 160 + (32 * 21), r));

	tiles.push_back(new Tile(1600, 160 + (32 * 16), r));
	tiles.push_back(new Tile(1600, 160 + (32 * 17), r));
	tiles.push_back(new Tile(1600, 160 + (32 * 18), r));
	tiles.push_back(new Tile(1600, 160 + (32 * 19), r));
	tiles.push_back(new Tile(1600, 160 + (32 * 20), r));
	tiles.push_back(new Tile(1600, 160 + (32 * 21), r));

	tiles.push_back(new Tile(1600, 160 + (32 * 0), r));
	tiles.push_back(new Tile(1600, 160 + (32 * 1), r));
	tiles.push_back(new Tile(1600, 160 + (32 * 2), r));
	tiles.push_back(new Tile(1600, 160 + (32 * 3), r));
	tiles.push_back(new Tile(1600, 160 + (32 * 4), r));
	tiles.push_back(new Tile(1600, 160 + (32 * 5), r));

	tiles.push_back(new Tile(1250, 160 + (32 * 6), r));
	tiles.push_back(new Tile(1250, 160 + (32 * 7), r));
	tiles.push_back(new Tile(1250, 160 + (32 * 8), r));
	tiles.push_back(new Tile(1250, 160 + (32 * 9), r));
	tiles.push_back(new Tile(1250, 160 + (32 * 10), r));
	tiles.push_back(new Tile(1250, 160 + (32 * 11), r));
	tiles.push_back(new Tile(1250, 160 + (32 * 12), r));
	tiles.push_back(new Tile(1250, 160 + (32 * 13), r));
	tiles.push_back(new Tile(1250, 160 + (32 * 14), r));
}

void Map::SetPool(std::list<GameObject *> *tilePool)
{
	this->tilePool = tilePool;
}

void Map::Init(Platform *platform)
{
	this->platform = platform;

	for (auto tile : tiles)
	{
		tile->Init(platform);
		tilePool->push_back(tile);
	}
}
void Map::Update()
{

}

void Map::Draw()
{

	for (auto tile : tiles)
	{
		tile->Draw();
	}

}

Map::~Map()
{
}
