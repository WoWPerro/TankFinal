#include "Platform.h"
#include "SDL.h"
#include<iostream>
#include "GameState.h"
#include <vector>


SDL_Renderer *Platform::renderer;

Platform::Platform(std::string name)
{
	width = 1920;
	height = 1080;

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init";
		return;
	}

	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "CreateWindow";
		SDL_Quit();
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << "CreateRenderer";
		SDL_Quit();
		return;
	}
}

void Platform::RenderClear()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Platform::RenderPresent()
{
	SDL_RenderPresent(renderer);
}


void Platform::DrawRect(int x, int y, int w, int h)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderDrawRect(renderer, &rect);
	
}

void Platform::RenderImage(Image *image, int x, int y, float angle)
{
	RenderTexture(image, x, y, angle);
}

void Platform::RenderTexture(Image * image,int x,int y, double a)
{
	SDL_Rect srcrect;
	srcrect.x = x;
	srcrect.y = y;
	srcrect.w = image->GetWidth();
	srcrect.h = image->GetHeight();
	SDL_RenderCopyEx(renderer, image->GetTexture()
		, NULL,&srcrect, a, NULL, SDL_FLIP_NONE);
}

Platform::~Platform()
{
}

std::vector<SDL_Event>& Platform::GetFrameEvents()
{
	static std::vector<SDL_Event> frame_events;
	return frame_events;
}

void Platform::CheckEvent(GameState *obj, bool (GameState::*f)(std::vector<int> *, std::vector<int> *))
{
	SDL_Event e;
	std::vector<int> keysDown;
	std::vector<int> keysUp;

	while (SDL_PollEvent(&e)) //El & sirve para obtener la dirección de memoria
	{
		switch (e.type)
		{
		case SDL_KEYDOWN:
			if (e.key.keysym.sym == SDLK_LEFT)
			{
				keysDown.push_back(SDLK_LEFT);
			}
			if (e.key.keysym.sym == SDLK_RIGHT)
			{
				keysDown.push_back(SDLK_RIGHT);
			}
			if (e.key.keysym.sym == SDLK_UP)
			{
				keysDown.push_back(SDLK_UP);
			}
			if (e.key.keysym.sym == SDLK_DOWN)
			{
				keysDown.push_back(SDLK_DOWN);
			}			
			if (e.key.keysym.sym == SDLK_SPACE)
			{
				keysDown.push_back(SDLK_SPACE);
			}
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				keysDown.push_back(SDLK_ESCAPE);
			}
			if (e.key.keysym.sym == SDLK_s)
			{
				keysDown.push_back(SDLK_s);
			}

			break;


		case SDL_KEYUP:
			if (e.key.keysym.sym == SDLK_LEFT)
			{
				keysUp.push_back(SDLK_LEFT);
			}
			if (e.key.keysym.sym == SDLK_RIGHT)
			{
				keysUp.push_back(SDLK_RIGHT);
			}
			if (e.key.keysym.sym == SDLK_UP)
			{
				keysUp.push_back(SDLK_UP);
			}
			if (e.key.keysym.sym == SDLK_DOWN)
			{
				keysUp.push_back(SDLK_DOWN);
			}
			if (e.key.keysym.sym == SDLK_SPACE)
			{
				keysUp.push_back(SDLK_SPACE);
			}
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				keysUp.push_back(SDLK_ESCAPE);
			}
			if (e.key.keysym.sym == SDLK_s)
			{
				keysUp.push_back(SDLK_s);
			}
			break;
		}
	}

	(obj->*f)(&keysDown, &keysUp);
}