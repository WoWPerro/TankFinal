#include "Game.h"
#include<iostream>
#include "Collision.h"

Game::Game()
{

}


Game::~Game()
{

}


void Game::Init(Platform * platform, GameStateManager *manager)
{
	player = new Tank();
	player->Init(platform);
	player->SetPool(&bulletPool, &tilePool, &tankPosX, &tankPosY);
	player->getPool(&bulletPoolEnemy);
	
	enemy = new HeavyTank();
	enemy->Init(platform);
	enemy->SetPool(&bulletPoolEnemy, &tilePool, &tankPosX, &tankPosY);
	enemy->getPool(&bulletPool);

	bullet = new Bullet(100, 100, player->GetAngle(), 10, 1);
	bullet->Init(platform);
	bullet->SetPool(&tilePool);
	
	map = new Map();
	map->SetPool(&tilePool);
	map->Init(platform);

	this->platform = platform;
	std::cout << " Game Init" << std::endl;
}

void Game::Draw()
{
	std::cout << " Game Draw" << std::endl;
	platform->RenderClear();	
	player->Draw();
	enemy->Draw();

	//A mayor numero menor velocidad del Gif
	
	for (auto object : bulletPool)
	{
		object->Draw();
	}

	for (auto object : bulletPoolEnemy)
	{
		object->Draw();
	}

	map->Draw();
	platform->RenderPresent();
}

bool Game::Input(std::vector<int> * keyUps, std::vector<int> * keyDowns)
{
	/*if (keyInput == 27)
	{
		
	}*/

	for (auto num : keyUps[0])
	{
		if (num == 27)
		{
			exit(1);
		}
	}

	for (auto num : keyDowns[0])
	{

	}

	player->Input(keyUps, keyDowns);

	std::cout << " Game Input" << std::endl;
	return false;
}

void Game::Update()
{
	for (auto object : bulletPool)
	{
		object->Update();
	}

	for (auto object : bulletPoolEnemy)
	{
		object->Update();
	}

	enemy->SetPositionsTank(player->GetPositionX() + player->GetRadius()/2, player->GetPositionY() + player->GetRadius() / 2);
	enemy->Update();
	player->Update();

	std::cout << " Game Update" << std::endl;

}

void Game::Close()
{
	std::cout << " Close Init" << std::endl;
}