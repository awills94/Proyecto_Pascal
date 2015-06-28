#include "Camaleon.h"
#include <iostream>

using namespace std;

Camaleon::Camaleon(SDL_Renderer *renderer)
{
    int w,h;
    textura = IMG_LoadTexture(renderer, "Camaleon.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 400;
    rect_textura.y = 490;
    rect_textura.w = w;
    rect_textura.h = h;

    velocidad=3;

    this->renderer = renderer;
//ctor
}


void Camaleon::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void Camaleon::logica()
{
    const Uint8* estaPresionada = SDL_GetKeyboardState( NULL );
    if(estaPresionada[ SDL_SCANCODE_LEFT])
    {
        if (rect_textura.x>0)
        rect_textura.x-=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_RIGHT])
    {
        if (rect_textura.x<850)
        rect_textura.x+=velocidad;
    }
//    if(estaPresionada[ SDL_SCANCODE_UP])
//    {
//        rect_textura.y-=velocidad;
//    }
//    if(estaPresionada[ SDL_SCANCODE_DOWN])
//    {
//        rect_textura.y+=velocidad;
//    }
            frame++;
//            cout<<frame<<endl;
}

