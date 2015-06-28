#include "Avispas.h"

Avispas::Avispas(SDL_Renderer *renderer)
{
     int w,h;
    textura = IMG_LoadTexture(renderer, "Avispa.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = Random;
    rect_textura.y = 0;
    rect_textura.w = w;
    rect_textura.h = h;

    velocidad=1;

    this->renderer = renderer;
}

void Avispas::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void Avispas::logica()
{
    rect_textura.y+=velocidad;
}


