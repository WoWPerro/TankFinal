#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Image.h"
#include "Gif.h"

class Menu : public GameState
{
private:
	Platform *platform;
	Image *background;
	GameStateManager *manager;
	Gif *test;
	Gif *test2;
public:
	Menu();
	~Menu();
	void Init(Platform * platform, GameStateManager *manager) override;
	void Draw() override;
	bool Input(std::vector<int> * keyDowns, std::vector<int> * keyUps) override;
	void Update() override;
	void Close() override;
};