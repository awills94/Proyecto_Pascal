#ifndef MOSCAS_H
#define MOSCAS_H

#include "Personaje.h"

class Moscas:public Personaje
{
    public:

        int Random = rand()%800 + 1;
        Moscas(SDL_Renderer *renderer);

        void dibujar();
        void logica();

    protected:
    private:
};

#endif // MOSCAS_H
