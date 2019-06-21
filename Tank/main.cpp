#include "SDL.h"
#include "GameStateManager.h"
#include "Menu.h"
int main(int argc, char *argv[])
{
	GameStateManager *manager = new GameStateManager();
	manager->SetState(new Menu());
	manager->GameLoop();
	delete manager;
	return 0;
}