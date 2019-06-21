#include "Menu.h"
#include "Game.h"
#include<iostream>


Menu::Menu()
{
	
}

Menu::~Menu()
{
}

void Menu::Init(Platform * platform, GameStateManager *manager)
{
	std::cout << " Menu Init" << std::endl;
	this->platform = platform;
	this->manager = manager;
	background = new Image();
	background->LoadImage("../Assets/Images/background.png");

	test = new Gif();
	test->Init(platform);
	test->SetPositionX(0);
	test->SetPositionY(0);
	test->AddImage("../Assets/Images/sprite_00.png");
	test->AddImage("../Assets/Images/sprite_01.png");
	test->AddImage("../Assets/Images/sprite_02.png");
	test->AddImage("../Assets/Images/sprite_03.png");
	test->AddImage("../Assets/Images/sprite_04.png");
	test->AddImage("../Assets/Images/sprite_05.png");
	test->AddImage("../Assets/Images/sprite_06.png");
	test->AddImage("../Assets/Images/sprite_07.png");
	test->AddImage("../Assets/Images/sprite_08.png");
	test->AddImage("../Assets/Images/sprite_09.png");
	test->AddImage("../Assets/Images/sprite_10.png");
	test->AddImage("../Assets/Images/sprite_11.png");
	test->AddImage("../Assets/Images/sprite_12.png");
	test->AddImage("../Assets/Images/sprite_13.png");
	test->AddImage("../Assets/Images/sprite_14.png");
	test->AddImage("../Assets/Images/sprite_15.png");
	test->AddImage("../Assets/Images/sprite_16.png");
	test->AddImage("../Assets/Images/sprite_17.png");
	test->AddImage("../Assets/Images/sprite_18.png");
	test->AddImage("../Assets/Images/sprite_19.png");
	test->AddImage("../Assets/Images/sprite_20.png");
	//test->AddImage("../Assets/Images/sprite_21.png");
	//test->AddImage("../Assets/Images/sprite_22.png");

	test2 = new Gif();
	test2->Init(platform);
	test2->SetPositionX(0);
	test2->SetPositionY(0);

	test2->AddImage("../Assets/Images/sprite_21.png");
	test2->AddImage("../Assets/Images/sprite_22.png");
}

void Menu::Draw()
{
	platform->RenderClear();
	std::cout << " Menu Draw" << std::endl;

	test->SetGifVel(3);
	test->SetLoop(false);
	test->Update();
	

	test2->SetGifVel(45);
	test2->SetLoop(true);

	if (test->finish == true)
	{
		test2->Update();
	}
	
	platform->RenderPresent();
}

bool Menu::Input(std::vector<int> *keyUps, std::vector<int> *keyDowns)
{
	std::cout << " Menu Input" << std::endl;

	for (auto num : keyUps[0])
	{
		
	}

	for (auto num : keyDowns[0])
	{
		if (num == 27)
		{
			exit(1);
		}
		else
		{
			manager->SetState(new Game());
		}
	}

	return false;
}

void Menu::Update()
{
	std::cout << " Menu Update" << std::endl;
}

void Menu::Close()
{
	std::cout << " Close Init" << std::endl;
}