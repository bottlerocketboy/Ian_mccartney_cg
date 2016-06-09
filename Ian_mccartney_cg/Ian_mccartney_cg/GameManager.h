#pragma once

#include "SDLInit.h"
extern SDL_Texture* background;
extern SDLInit sdlInit;

class GameManager{
	public:
		static bool Init();
		static bool Cleanup();
		
		static void Draw();
		static void Update();
};