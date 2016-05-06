//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

#define GAME_NAME "Space Rocks" //TODO: find way to move to game manager.

class SDLInit{

	public:
		bool Setup();
		bool Cleanup();
		void Update();
};