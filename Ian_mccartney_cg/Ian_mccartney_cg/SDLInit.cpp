
#include "SDL.h"
#include <stdio.h>
#include <string>
#include "SDL_image.h"
#include "SDLInit.h"
#include "SDL_surface.h"
#include "LTexture.h"
#include "GameManager.h"

using namespace std;

//extern SDL_Renderer* gRenderer;

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool sdlQuit = false;
SDL_Event event;

//The window we'll be rendering to
SDL_Window* window = NULL;

//The surface contained by the window
SDL_Surface* screenSurface = NULL;
//current Texture
SDL_Texture* gTexture = NULL;

SDLInit::SDLInit(){
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

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


		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

void SDLInit::DrawImage(SDL_Texture* sdl_Texture,SDL_Rect texCoords, SDL_Rect scnCoords) {
	//Render texture to screen
	//SDL_Rect scn;

	//screenRect.x = 0;
	//screenRect.y = 0;
	//screenRect.h = 33;
	//screenRect.w = 15;

	//SDL_Rect textureRect;
	//textureRect.x = 0;
	//textureRect.y = 0;
	//textureRect.h = 37;
	//textureRect.w = 15;
	SDL_RenderCopy(gRenderer, sdl_Texture, &texCoords, &scnCoords);
}

//TODO: add delta time to update...
void SDLInit::Update(){
	
	while (!sdlQuit){
		//Handle events on queue
		while (SDL_PollEvent(&event) != 0)
		{
			//User requests quit
			if (event.type == SDL_QUIT)
			{
				sdlQuit = true;
			}
		}

		//Clear screen
		SDL_RenderClear(gRenderer);

		GameManager::Update();

		//Update screen
		SDL_RenderPresent(gRenderer);
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

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

SDL_Texture* SDLInit::loadMedia(const char* imageName)
{
	SDL_Texture* sdlTexture;

	//Load PNG texture
	sdlTexture = loadTexture(imageName);
	if (sdlTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		
	}

	return sdlTexture;
}

	////Return success
	//mTexture = newTexture;
	//return mTexture != NULL;
	
	
	
	
	
	//bool success = true;
	//
	////*surface = SDL_LoadBMP(imgName);
	//*surface = loadSurface(imgName);/////////////////////////////////////2.) TODO: THIS IS WHERE NEW TEXTURE INFO GOES
	//if (*surface == NULL){
	//	printf("SDL FAILED AT SDL_LoadBMP %s", imgName);
	//	success = false;
	//}

	//return success;
//}
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

//
//void SDLInit::drawImg(SDL_Surface* img){		//TODO:: 1.) We are noot drawing surfaces anymore,MOving to textures
//	SDL_BlitSurface(img, NULL, screenSurface, NULL);
//}

//void RenderImage(SDL_Texture* texture) {
//	//Render texture to screen
//	SDL_RenderCopy(gRenderer, texture, NULL, NULL);
//}

void close()
{
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy window    
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(window);
	window = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

//////////////////////////////..........................................................
void SDLInit::Free() {
	//Free texture if it exists
	if (mTexture != NULL) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}