#include "GameManager.h"
#include "SDLInit.h"
#include "ship.h"

extern SDL_Window* window;
extern SDL_Surface* screenSurface;

//Screen dimension constants
extern int SCREEN_WIDTH;		//TODO: currently not using...
extern int SCREEN_HEIGHT;		//TODO: currently not using...

SDLInit sdlInit;

SDL_Texture* background = NULL;

//TODO: Move later...
namespace  {
	//Images to be loaded go here
	const char* backroundImgName = "game_area.png";
	const char* ShipImgName = "ship.png";
	const char* backround_frame = "game_area_frame.png";

	//Loaded images...
	SDL_Surface* backround = NULL;
	SDL_Surface* ShipLayer = NULL;
	SDL_Surface* frameLayer = NULL;

}
/////////////////////////////////////////////////////////////////////Probably going to move this to ship.cpp(MOVED FOR NOW< WATCH DUPLICATE IN SHIP.H)
//enum KeyPressEvent{
//	KEY_PRESS_SURFACE_DEFAULT,
//	KEY_PRESS_SURFACE_UP,
//	KEY_PRESS_SURFACE_DOWN,
//	KEY_PRESS_SURFACE_LEFT,
//	KEY_PRESS_SURFACE_RIGHT,
//	KEY_PRESS_SURFACE_TOTAL
//};






//not sure i need this???
//SDL_Surface* gKeyPressSur[KEY_PRESS_SURFACE_TOTAL];

bool GameManager::Init(){
	bool initSuccess = sdlInit.Setup();

	if(initSuccess){
		background = sdlInit.loadMedia(backroundImgName);
		//sdlInit.loadMedia(backroundImgName, &backround);
		//sdlInit.loadMedia(ShipImgName, &ShipLayer);
		//sdlInit.loadMedia(backround_frame, &frameLayer);
	}

	return initSuccess;
}

bool GameManager::Cleanup(){
	return sdlInit.Cleanup();
}

//TODO: Add deltatime later...
void GameManager::Draw(){
	//sdlInit.drawImg(backround);
	//sdlInit.drawImg(ShipLayer);
	//sdlInit.drawImg(frameLayer);////////NEED HELP WITH FRAME IMG (probably need to load as PNG)

}

//TODO: Add deltatime later...
void GameManager::Update(){
	SDLInit::DrawImage(background);
}//Don't change this right now..



/////////////////////////////////////////////////////////////
//
// KEY PRESS SECTION
//
/////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////

