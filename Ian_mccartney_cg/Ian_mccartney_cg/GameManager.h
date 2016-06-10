#pragma once

#include "SDLInit.h"
extern SDL_Texture* background_t;
extern SDL_Texture* ShipLayer_t;


extern SDLInit sdlInit;

class GameManager{

	public:
		static bool Init();
		static bool Cleanup();
		
		static void Draw();
		static void Update();
};