#pragma once
#include <string>
#include "SDL.h"
#include "Image.h"
#include "GameState.h"
#include <vector>

class GameState;

class Platform
{
private:
	int width;
	int height;
	SDL_Window *window;
public:
	static SDL_Renderer *renderer;
	Platform(std::string name);
	~Platform();
	void RenderClear();
	void RenderImage(Image *image, int x, int y, float angle);
	void RenderPresent();

	std::vector <SDL_Event>& GetFrameEvents();
	void CheckEvent(GameState *obj, bool (GameState::*f)(std::vector<int> *, std::vector<int> *));

	void DrawRect(int x, int y, int w, int h);
private:
	void RenderTexture(Image * image, int x, int y, double a);

};

