#include "Moscas.h"
#include <iostream>

using namespace std;

Moscas::Moscas(SDL_Renderer *renderer)
{
    int w,h;
    textura = IMG_LoadTexture(renderer, "Mosca.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = Random;
    rect_textura.y = 0;
    rect_textura.w = w;
    rect_textura.h = h;

    velocidad=1;

    this->renderer = renderer;
        //ctor
}

void Moscas::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void Moscas::logica()
{
    rect_textura.y+=velocidad;

}

