#include "input.h"
#include <stdio.h>

int input_handler(Entity *entity, Entity *enemy, Entity *enemy2, Entity *enemy3, Entity *enemy4, Entity *enemy5) {
    SDL_Event event;

    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT :
        return -1;
    case SDL_KEYDOWN :
        printf("The key that you have pushed is down\n");
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            entity->pos_y -= 4;
            break;
        case SDLK_DOWN:
            entity->pos_y += 4;
            break;
        case SDLK_LEFT:
            entity->pos_x -= 4;
            printf("The key that you have pushed is left\n");
            break;
        case SDLK_RIGHT:
        printf("The key that you have pushed is right\n");
            entity->pos_x += 4;
            break;
    case SDL_KEYUP :
        printf("The key that you have pushed is up\n");
        break;


    default:
        break;
        }
        enemy->pos_x -= 7;
        enemy2->pos_x -= 10;
        enemy3->pos_x -= 5;
        enemy4->pos_x -= 11;
        enemy5->pos_x -= 5;

        if (entity->pos_x <= 0) entity->pos_x = 0;
        if (entity->pos_y <= 0) entity->pos_y = 0;
        if (entity->pos_x >= WINDOW_WIDTH - entity->width) entity->pos_x = WINDOW_WIDTH - entity->width;
        if (entity->pos_y >= WINDOW_HEIGHT - entity->height) entity->pos_y = WINDOW_HEIGHT - entity->height;

        SDL_Delay(1000/60);
    } return 0;
}