#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class Personaje
{
    public:
        Personaje();
        SDL_Texture *textura;
        SDL_Renderer *renderer;
        SDL_Rect rect_textura;
        int velocidad;
        virtual void logica()=0;
        virtual void dibujar()=0;
        int frame;

        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
