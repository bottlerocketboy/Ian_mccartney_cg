#pragma once

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string>
#include "SDL_image.h"

using namespace std;

#define GAME_NAME "Space Rock Armageddon" //TODO: find way to move to game manager.

extern bool sdlQuit;
extern SDL_Event event;

class SDLInit{

	public:
		SDLInit();

		bool Setup();
		bool Cleanup();
		void Update();
		SDL_Texture* SDLInit::loadMedia(const char* imageName);
		//bool loadMedia(const char* imgName, SDL_Surface **surface);
		SDL_Surface* loadSurface(std::string path);
		static void DrawImage(SDL_Texture* sdl_Texture, SDL_Rect texCoords, SDL_Rect scnCoords);
		
		//Deallocates texture
		void Free();
private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;


};
