#include "GameManager.h"
#include "SDLInit.h"
#include "ship.h"
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
	const char* ShipImgName = "ship.bmp";
	const char* backround_frame = "game_area_frame.bmp";

	//Loaded images...
	SDL_Surface* backround = NULL;
	SDL_Surface* ShipLayer = NULL;
	SDL_Surface* frameLayer = NULL;



}

bool GameManager::Init(){
	bool initSuccess = sdlInit.Setup();

	if(initSuccess){
		sdlInit.loadMedia(backroundImgName, &backround);
		sdlInit.loadMedia(ShipImgName, &ShipLayer);
		sdlInit.loadMedia(backround_frame, &frameLayer);
	}


	return initSuccess;
}

bool GameManager::Cleanup(){
	return sdlInit.Cleanup();
}

//TODO: Add deltatime later...
void GameManager::Draw(){
	sdlInit.drawImg(backround);
	sdlInit.drawImg(ShipLayer);
//	sdlInit.drawImg(frameLayer);////////NEED HELP WITH FRAME IMG

}

//TODO: Add deltatime later...
void GameManager::Update(){
	sdlInit.Update();
}//Don't change this right now..
<<<<<<< HEAD


/////////////////////////////////////////////////////////////
//
// KEY PRESS SECTION
//
/////////////////////////////////////////////////////////////

enum KeyPressSUR
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};


/////////////////////////////////////////////////////////////
=======
>>>>>>> 069c552f4840ea2a5eb9c239c54502f58e9ca2c0
