#include <iostream>
#include <SDL2/SDL.h>
#include "../include/Game.hpp"

Game game;
const int FPS = 40;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argv, char** args)
{
	Uint32 frameStart, frameTime;

	game.init("Game", 800, 640);

	while (game.is_Running())
	{
		frameStart = SDL_GetTicks();

		game.handleEvents();
		game.update();
		game.render();

		frameTime = SDL_GetTicks() - frameStart;
		if(frameTime < DELAY_TIME)
		{
			SDL_Delay(int(DELAY_TIME - frameTime));
		}
	}
	return 0;
}