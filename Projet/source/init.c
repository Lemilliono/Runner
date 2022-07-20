#include "init.h"

int initSDL(Win *app)
{
   if (SDL_Init(SDL_INIT_VIDEO) < 0) {
       printf("Ne peux pas initialiser SDL: %s\n", SDL_GetError());
       return -1;
   }

    app->window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if(!app->window)
    {
        printf("Failed to open %d x %d Windows : %s\n", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_GetError());
        return -1;
    }

    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
    if (!app->renderer) {
        printf(SDL_GetError(), "ERROR: ");
        return -1;


    }
    return 0;

}