#ifndef CAMALEON_H
#define CAMALEON_H

#include "Personaje.h"

class Camaleon:public Personaje
{
    public:
        Camaleon(SDL_Renderer *renderer);

        void dibujar();
        void logica();

    protected:
    private:
};

#endif // CAMALEON_H
