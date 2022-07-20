#include "draw.h"
#include "window.h"

void prepareCanvas(Win *app)
{

    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);

    SDL_RenderClear(app->renderer);
}

void presentCanvas(Win *app)
{
    SDL_RenderPresent(app->renderer);
}

SDL_Texture *loadTexture(Win *app, char *img_path)
{
    SDL_Texture *texture;
    
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading: %s", img_path);
    texture = IMG_LoadTexture(app->renderer, img_path);
    if (texture == NULL) {
        printf("ERROR!! Failed to load texture %s\n", IMG_GetError());
    }
    return texture;
}

int check_collision( SDL_Rect *player, SDL_Rect *enemy, SDL_Rect *enemy2, SDL_Rect *enemy3, SDL_Rect *enemy4, SDL_Rect *enemy5)
{
    int leftplayer, leftenemy, leftenemy2, leftenemy3, leftenemy4, leftenemy5;
    int rightplayer, rightenemy, rightenemy2, rightenemy3, rightenemy4, rightenemy5;
    int topplayer, topenemy, topenemy2, topenemy3, topenemy4, topenemy5;
    int bottomplayer, bottomenemy, bottomenemy2, bottomenemy3, bottomenemy4, bottomenemy5 ;

    leftplayer = player->x;
    rightplayer = player->x + player->w;
    topplayer = player->y;
    bottomplayer = player->y + player->h;

    leftenemy = enemy->x;
    rightenemy = enemy->x +enemy->w;
    topenemy = enemy->y;
    bottomenemy = enemy->y + enemy->h;

    leftenemy2 = enemy2->x;
    rightenemy2 = enemy2->x +enemy2->w;
    topenemy2 = enemy2->y;
    bottomenemy2 = enemy2->y + enemy2->h;

    leftenemy3 = enemy3->x;
    rightenemy3 = enemy3->x +enemy3->w;
    topenemy3 = enemy3->y;
    bottomenemy3 = enemy3->y + enemy3->h;

    leftenemy4 = enemy4->x;
    rightenemy4 = enemy4->x +enemy4->w;
    topenemy4 = enemy4->y;
    bottomenemy4 = enemy4->y + enemy4->h;

    leftenemy5 = enemy5->x;
    rightenemy5 = enemy5->x +enemy5->w;
    topenemy5 = enemy5->y;
    bottomenemy5 = enemy5->y + enemy5->h;

    if( bottomplayer <= topenemy || bottomplayer <= topenemy2 || bottomplayer <= topenemy3 || bottomplayer <= topenemy4 || bottomplayer <= topenemy5 )
    {
      return 0;
    }
 
    if( topplayer >= bottomenemy || topplayer >= bottomenemy2 || topplayer >= bottomenemy3 || topplayer >= bottomenemy4 || topplayer >= bottomenemy5 )
    {
      return 0;
    }
 
    if( rightplayer <= leftenemy || rightplayer <= leftenemy2 || rightplayer <= leftenemy3 || rightplayer <= leftenemy4 || rightplayer <= leftenemy5 )
    {
      return 0;
    }
 
    if( leftplayer >= rightenemy || leftplayer >= rightenemy2 || leftplayer >= rightenemy3 || leftplayer >= rightenemy4 || leftplayer >= rightenemy5 )
    {
      return 0;
    }

    //Si conditions collision detectee
    return -1;
}

int drawEntity(Win *app,Entity *entity, Entity *enemy, Entity *enemy2, Entity *enemy3, Entity *enemy4, Entity *enemy5)
{
    SDL_Rect dest = {entity->pos_x, entity->pos_y, entity->width, entity->height};

    SDL_Rect messi = {enemy->pos_x, enemy->pos_y, enemy->width, enemy->height};

    SDL_Rect barca = {enemy2->pos_x, enemy2->pos_y, enemy2->width, enemy2->height};

    SDL_Rect catalogne = {enemy3->pos_x, enemy3->pos_y, enemy3->width, enemy3->height};

    SDL_Rect portaventura = {enemy4->pos_x, enemy4->pos_y, enemy4->width, enemy4->height};

    SDL_Rect campnou = {enemy5->pos_x, enemy5->pos_y, enemy5->width, enemy5->height};


    
    SDL_RenderCopy(app->renderer, entity->texture, NULL, &dest);

    SDL_RenderCopy(app->renderer, enemy->texture, NULL, &messi);

    SDL_RenderCopy(app->renderer, enemy2->texture, NULL, &barca);

    SDL_RenderCopy(app->renderer, enemy3->texture, NULL, &catalogne);

    SDL_RenderCopy(app->renderer, enemy4->texture, NULL, &portaventura);

    SDL_RenderCopy(app->renderer, enemy5->texture, NULL, &campnou);

    if(check_collision(&dest, &messi, &barca, &catalogne, &portaventura, &campnou))
    {
        printf("GAME OVER !!!");
        return -1;
    }
    return 0;
}

