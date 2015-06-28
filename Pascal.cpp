#include "Pascal.h"

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
using namespace std;

SDL_Renderer* renderer;
SDL_Texture *textura;
SDL_Rect rect_textura;

Pascal::Pascal()
{
    int w,h;

    textura = IMG_LoadTexture(renderer, "Camaleon.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 0;
    rect_textura.y = 100;
    rect_textura.w = w;
    rect_textura.h = h;
    //ctor
}

Pascal::~Pascal()
{
    //dtor
}
