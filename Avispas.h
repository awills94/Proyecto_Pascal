#ifndef AVISPAS_H
#define AVISPAS_H
#include "Personaje.h"

class Avispas:public Personaje
{
    public:

        int Random = rand()%800 + 2;
        Avispas(SDL_Renderer *renderer);

        void dibujar();
        void logica();


    protected:
    private:
};

#endif // AVISPAS_H
