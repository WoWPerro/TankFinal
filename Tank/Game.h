#pragma once
#include "GameState.h"
#include "Tank.h"
#include"HeavyTank.h"
#include "Bullet.h"
#include "Map.h"
#include <list>

//4 cosas:
//
//visuales míos
//Musica
//
//Progra :
//Disparo al jugador
//Gif
//
//- Intro
//- Menu
//- Acabar el juego
//- cámara
//- Sonidos

class Game : public GameState
{
private:
	Platform * platform;
	Tank *player;
	HeavyTank *enemy;
	Bullet *bullet;
	Map *map;

	std::list<GameObject *> bulletPool;
	std::list<GameObject *> bulletPoolEnemy;
	std::list<GameObject *> tilePool;
	std::list<GameObject *> tankPool;
	std::list<float *> tankPosX;
	std::list<float *> tankPosY;

public:
	Game();
	~Game();
	void Init(Platform * platform, GameStateManager *manager) override;
	void Draw() override;
	bool Input(std::vector<int> *keyDowns, std::vector<int> *keyUps) override;
	void Update() override;
	void Close() override;
};

