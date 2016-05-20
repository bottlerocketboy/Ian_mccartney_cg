#include "GameManager.h"
#include "SDLInit.h"

extern SDL_Window* window;
extern SDL_Surface* screenSurface;

//Screen dimension constants
extern int SCREEN_WIDTH;		//TODO: currently not using...
extern int SCREEN_HEIGHT;		//TODO: currently not using...

static SDLInit sdlInit;

//TODO: Move later...
namespace  {
	//Images to be loaded go here
	const char* backroundImgName = "game_area.bmp";


	//Laded images...
	SDL_Surface* backround = NULL;


}

bool GameManager::Init(){
	bool initSuccess = sdlInit.Setup();

	if(initSuccess){
		sdlInit.loadMedia(backroundImgName, &backround);
	
	}


	return initSuccess;
}

bool GameManager::Cleanup(){
	return sdlInit.Cleanup();
}

//TODO: Add deltatime later...
void GameManager::Draw(){
	sdlInit.drawImg(backround);
}

//TODO: Add deltatime later...
void GameManager::Update(){
	sdlInit.Update();
}
