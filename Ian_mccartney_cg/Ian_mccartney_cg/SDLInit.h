//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

#define GAME_NAME "Space Rock Armageddon" //TODO: find way to move to game manager.

class SDLInit{

	public:
		bool Setup();
		bool Cleanup();
		void Update();
		bool loadMedia(const char* imgName, SDL_Surface **surface);
		void drawImg(SDL_Surface* img);

};