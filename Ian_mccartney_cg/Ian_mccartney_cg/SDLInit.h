#pragma once

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string>
#include "SDL_image.h"

using namespace std;

#define GAME_NAME "Space Rock Armageddon" //TODO: find way to move to game manager.

class SDLInit{

	public:
		SDLInit();

		bool Setup();
		bool Cleanup();
		void Update();
		bool loadMedia(const char* imgName, SDL_Surface **surface);
		SDL_Surface* loadSurface(std::string path);
		void drawImg(SDL_Surface* img);

};