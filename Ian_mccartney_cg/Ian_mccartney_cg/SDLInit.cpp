
#include "SDL.h"
#include <stdio.h>
#include <string>
#include "SDL_image.h"
#include "SDLInit.h"
#include "SDL_surface.h"


using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool sdlQuit = false;
static SDL_Event event;

//The window we'll be rendering to
SDL_Window* window = NULL;

//The surface contained by the window
SDL_Surface* screenSurface = NULL;
//current Texture
SDL_Texture* gTexture = NULL;



bool SDLInit::Setup(){
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}


		//Create window				//TODO: Make this name global...
		window = SDL_CreateWindow( GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError()); //gives unresolved external
					success = false;
				}
				else
				{

					//Get window surface
					
					screenSurface = SDL_GetWindowSurface(window);
				}
		
		}
	}

	return success;
}

SDLInit::SDLInit() {

}

//TODO: add delta time to update...
void SDLInit::Update(){
	
	//Update the surface
	SDL_UpdateWindowSurface(window);



	/* Poll for events */
	while (SDL_PollEvent(&event)){

		switch (event.type){
			//	/* Keyboard event */
			//	/* Pass the event data onto PrintKeyInfo() */
			//case SDL_KEYDOWN:
			//case SDL_KEYUP:
			//	PrintKeyInfo(&event.key);
			//	break;

			
		case SDL_QUIT:
			sdlQuit = true;
			break;

		default:
			break;
		}
	}
}

bool SDLInit::Cleanup(){
	bool initSuccess = true;

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return initSuccess;
}

//using double pointer so the value is not lost
bool SDLInit::loadMedia(const char* imgName, SDL_Surface **surface){
	bool success = true;
	
	//*surface = SDL_LoadBMP(imgName);
	*surface = loadSurface(imgName);/////////////////////////////////////
	if (*surface == NULL){
		printf("SDL FAILED AT SDL_LoadBMP %s", imgName);
		success = false;
	}

	return success;
}
///////////////////////////////////////////////////////////////////////////////////////////
SDL_Surface* SDLInit::loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	/*loadedSurface = SDL_CreateTextureFromSurface(,optimizedSurface);*/
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);

	}

	return optimizedSurface;
}
/////////////////////////////////////////////////////////////////////////////////


void SDLInit::drawImg(SDL_Surface* img){
	SDL_BlitSurface(img, NULL, screenSurface, NULL);
}