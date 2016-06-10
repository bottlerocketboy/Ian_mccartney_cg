#include "GameManager.h"
#include "SDLInit.h"
#include "ship.h"

extern SDL_Window* window;
extern SDL_Surface* screenSurface;

//Screen dimension constants
extern int SCREEN_WIDTH;		//TODO: currently not using...
extern int SCREEN_HEIGHT;		//TODO: currently not using...

SDLInit sdlInit;

SDL_Texture* background_t = NULL;
SDL_Texture* ShipLayer_t = NULL;





//TODO: Move later...
namespace  {
	//Images to be loaded go here
	const char* backroundImgName = "game_area.png";
	const char* ShipImgName = "ship.png";
	const char* backround_frame = "game_area_frame.png";

	//Loaded images...
	SDL_Surface* background_s = NULL;
	SDL_Surface* ShipLayer_s = NULL;
	SDL_Surface* frameLayer_s = NULL;


}

bool GameManager::Init(){
	bool initSuccess = sdlInit.Setup();

	if(initSuccess){
		background_t = sdlInit.loadMedia(backroundImgName);
		ShipLayer_t = sdlInit.loadMedia(ShipImgName);
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
	//RECTS

	SDL_Rect gameAreaRect;
	gameAreaRect.x = 0;
	gameAreaRect.y = 0;
	gameAreaRect.w = 800;
	gameAreaRect.h = 600;
	SDLInit::DrawImage(background_t, gameAreaRect, gameAreaRect);

	SDL_Rect gameShipRect;
	gameShipRect.x = 400;
	gameShipRect.y = 300;
	gameShipRect.w = 33;
	gameShipRect.h = 37;
	SDLInit::DrawImage(ShipLayer_t, gameAreaRect, gameShipRect);


	

}//Don't change this right now..


