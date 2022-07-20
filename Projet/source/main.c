#include <stdio.h>
#include "window.h"
#include "input.h"
#include "draw.h"
#include "init.h"

int main()
{
    Win *app = malloc(sizeof(Win));
    Entity *player = malloc(sizeof(Entity));
    Entity *enemy = malloc(sizeof(Entity));
    Entity *enemy2 = malloc(sizeof(Entity));
    Entity *enemy3 = malloc(sizeof(Entity));
    Entity *enemy4 = malloc(sizeof(Entity));
    Entity *enemy5 = malloc(sizeof(Entity));

    if (initSDL(app) < 0)
    {
        return -1;
    }

    player->pos_x = 100;
    player->pos_y = 100;
    player->width = 50;
    player->height = 50;
    player->texture = loadTexture(app, "ressource/player.png"   );

    enemy->pos_x = 200;
    enemy->pos_y = 160;
    enemy->width =180;
    enemy->height = 130;
    enemy->texture = loadTexture(app, "ressource/enemy.png"   );

    enemy2->pos_x = 174;
    enemy2->pos_y = 60;
    enemy2->width =180;
    enemy2->height = 130;
    enemy2->texture = loadTexture(app, "ressource/enemy.png"   );


    enemy3->pos_x = 360;
    enemy3->pos_y = 10;
    enemy3->width =180;
    enemy3->height = 130;
    enemy3->texture = loadTexture(app, "ressource/enemy.png"   );


    enemy4->pos_x = 900;
    enemy4->pos_y = 360;
    enemy4->width =180;
    enemy4->height = 130;
    enemy4->texture = loadTexture(app, "ressource/enemy.png"   );


    enemy5->pos_x = 700;
    enemy5->pos_y = 32;
    enemy5->width =180;
    enemy5->height = 130;
    enemy5->texture = loadTexture(app, "ressource/enemy.png"   );


    while (input_handler(player, enemy, enemy2, enemy3, enemy4, enemy5) == 0)
    {
        prepareCanvas(app);
        if(drawEntity(app, player, enemy, enemy2, enemy3, enemy4, enemy5) == -1)
        {
            return 0;
        }
        presentCanvas(app);
        SDL_Delay(16);
    }
    free(app);
    free(player);
    free(enemy);
    free(enemy2);
    free(enemy3);
    free(enemy4);
    free(enemy5);

    return 0;
}



