#include <SDL2/SDL.h>
#include <stdio.h>

#ifndef WIDTH
    #define WIDTH 640;
#endif

#ifndef HEIGHT
    #define HEIGHT 480;
#endif

#define UBYTE uint8_t
#define UWORD uint16_t

class SdlScreen {
    public : 
        void handleEvent();
        void display(UBYTE * image);
        SdlScreen();
        ~SdlScreen();
        bool quit = false;

    private :
        const int SCREEN_WIDTH = WIDTH;
        const int SCREEN_HEIGHT = HEIGHT;
        void init();
        SDL_Window *window;
        //SDL_Surface *screenSurface;
        SDL_Renderer *renderer;
        SDL_Texture *texture;
        SDL_Event event;
        Uint32 * pixels;
};

void SdlScreen::handleEvent() {
    SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) quit = true;
}

void SdlScreen::display(UBYTE * image) {
    // map from byte to array
    //UWORD w = (WIDTH % 8 == 0) ? (WIDTH/8) : (WIDTH/8+1);
    UWORD w = 80;
    UWORD h = HEIGHT;
    for (UWORD j = 0; j < h; j++) {
        for (UWORD i = 0; i < w; i++) {
            uint8_t value;
            if(image[i+j*w]) value = 255;
            else value = 0;
            pixels[i+j*w] = value;
        }
    }
	SDL_UpdateTexture(texture, NULL, pixels, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

SdlScreen::SdlScreen() {
    // Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	} else {
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);
		texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
			
		pixels = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		memset(pixels, 255, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}

    }

}

SdlScreen::~SdlScreen() {
	delete[] pixels;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);	
    // Destroy window
	SDL_DestroyWindow(window);
	// Quit SDL subsystems
	SDL_Quit();
}
