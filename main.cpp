#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<SDL2/SDL_ttf.h>
#include<list>

#include "Pascal.h"
#include "Camaleon.h"
#include "Moscas.h"
#include "Avispas.h"


SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *Fondo;
SDL_Rect rect_Fondo;
SDL_Rect rect_MoscasComidas;
SDL_Rect rect_MoscasPasadas;
SDL_Rect rect_background;

using namespace std;

    list<Moscas*>List_moscas;
    list<Avispas*>List_Avispas;

    std::string toString(int number)
{
if (number == 0)
return "0";
if(number < 0)
return "-"+toString(-number);
std::string temp="";
std::string returnvalue="";
while (number>0)
{
temp+=number%10+48;
number/=10;
}
for (int i=0; i<(int)temp.length(); i++)
returnvalue+=temp[temp.length()-i-1];
return returnvalue;
}

void FinJuego()
{

}

void Juego()
{

    int MoscasPasadas=0;
    int MoscasComidas=0;

    string MC= "Moscas Comidas " + toString(MoscasComidas);
    string MP= "Moscas Pasadas " + toString(MoscasPasadas);


    rect_MoscasComidas.x = 10;
    rect_MoscasComidas.y = 10;
    rect_MoscasComidas.w = 350;
    rect_MoscasComidas.h = 50;

    rect_MoscasPasadas.x = 600;
    rect_MoscasPasadas.y = 10;
    rect_MoscasPasadas.w = 350;
    rect_MoscasPasadas.h = 50;


SDL_Color Color = {100,170,0};
TTF_Font *Font = TTF_OpenFont("Font.ttf", 300);

SDL_Surface* Temp = TTF_RenderText_Solid(Font,MC.c_str(), Color);
SDL_Surface* Temp2 = TTF_RenderText_Solid(Font,MP.c_str(), Color);


SDL_Texture* Texto = SDL_CreateTextureFromSurface(renderer,  Temp);
SDL_Texture* Texto2 = SDL_CreateTextureFromSurface(renderer,  Temp);


int w=0,h=0;
    Fondo = IMG_LoadTexture(renderer,"Fondo.png");
    SDL_QueryTexture(Fondo, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;




unsigned int frame_anterior = SDL_GetTicks();

    Camaleon camaleon(renderer);

//    Moscas mosca(renderer);

    int frame=0;



    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                 if(Event.type == SDL_KEYDOWN)
                    {
                        if(Event.key.keysym.sym == SDLK_RETURN)
                        {
                            Juego();
                        }
                        if(Event.key.keysym.sym == SDLK_p)
                        {
                            return;
                            List_Avispas.clear();
                            List_moscas.clear();
                        }
                    }
            }
        }


            SDL_RenderCopy(renderer, Fondo, NULL, &rect_background);
            camaleon.dibujar();
            camaleon.logica();

            MC= "Moscas Comidas " + toString(MoscasComidas);
            MP= "Moscas Pasadas " + toString(MoscasPasadas);
            Temp = TTF_RenderText_Solid(Font,MC.c_str(), Color);
            Temp2 = TTF_RenderText_Solid(Font,MP.c_str(), Color);
            Texto = SDL_CreateTextureFromSurface(renderer, Temp);
            Texto2 = SDL_CreateTextureFromSurface(renderer, Temp2);

            SDL_RenderCopy(renderer, Texto, NULL, &rect_MoscasComidas);
            SDL_RenderCopy(renderer, Texto2, NULL, &rect_MoscasPasadas);

            SDL_FreeSurface(Temp);
            SDL_DestroyTexture(Texto);
            SDL_FreeSurface(Temp2);
            SDL_DestroyTexture(Texto2);

                    int tempFrame;

                    if (tempFrame+30<frame)
                    {
                    SDL_DestroyTexture(camaleon.textura);
                    camaleon.textura = IMG_LoadTexture(renderer, "Camaleon.png");
                    }

                    if (frame<1000)
                    {
                        if(frame%300==0)
                        {
                            List_moscas.push_back(new Moscas(renderer));
                        }
                    }

                    else if (frame<2000)
                    {
                        if(frame%250==0)
                        {
                            List_moscas.push_back(new Moscas(renderer));
                        }
                    }


                    else if (frame<3000)
                    {
                        if(frame%200==0)
                        {
                            List_moscas.push_back(new Moscas(renderer));

                        }
                    }

                    else if (frame<4000)
                    {
                        if(frame%150==0)
                        {
                            List_moscas.push_back(new Moscas(renderer));
                            SDL_DestroyTexture(Fondo);
                            Fondo = IMG_LoadTexture(renderer,"Fondo1.png");
                        }


                        if(frame%300==0)
                        {
                            List_Avispas.push_back(new Avispas(renderer));
                        }

                    }

                    else if (frame<7000)
                    {
                        if(frame%100==0)
                        {
                            List_moscas.push_back(new Moscas(renderer));
                        }

                        if(frame%150==0)
                        {
                            List_Avispas.push_back(new Avispas(renderer));
                        }
                    }


                    else if (frame>7000)
                    {
                        if(frame%50==0)
                        {
                            List_moscas.push_back(new Moscas(renderer));
                            SDL_DestroyTexture(Fondo);
                            Fondo = IMG_LoadTexture(renderer,"Fondo2.png");
                        }
                    }



                    for(list<Avispas*>::iterator i=List_Avispas.begin(); i!=List_Avispas.end(); i++)
                        {
                            (*i)->dibujar();
                            (*i)->logica();

                             if((*i)->rect_textura.y>420 & (*i)->rect_textura.y<460)
                                {
                                    int tempmax = (*i)->rect_textura.x + 30;
                                    int tempmin = (*i)->rect_textura.x - 30;

                                    if(camaleon.rect_textura.x<=tempmax & camaleon.rect_textura.x>=tempmin)
                                    {
                                      List_Avispas.erase(i);
                                      List_Avispas.clear();
                                      List_moscas.clear();
                                      return;
                                    }
                                }
                        }



                    for(list<Moscas*>::iterator i=List_moscas.begin(); i!=List_moscas.end(); i++)
                        {
                            (*i)->dibujar();
                            (*i)->logica();

                                if((*i)->rect_textura.y==600)
                                {
                                MoscasPasadas++;
                                List_moscas.erase(i);
                                break;
                                }

                                if((*i)->rect_textura.y>430 & (*i)->rect_textura.y<460)
                                {
                                    int tempmax = (*i)->rect_textura.x + 50;
                                    int tempmin = (*i)->rect_textura.x - 50;

                                    if(camaleon.rect_textura.x<=tempmax & camaleon.rect_textura.x>=tempmin)
                                    {
                                    MoscasComidas++;
                                    List_moscas.erase(i);

                                    tempFrame=frame;
                                      SDL_DestroyTexture(camaleon.textura);
                                      camaleon.textura = IMG_LoadTexture(renderer, "Camaleon2.png");
                                      break;
                                    }


                                }
                        }




                    if((SDL_GetTicks()-frame_anterior)<10)
                    SDL_Delay(10-(SDL_GetTicks()-frame_anterior));
                    frame_anterior=SDL_GetTicks();


                    cout<<MoscasComidas<<endl;


            SDL_RenderPresent(renderer);
            frame++;




            if(MoscasPasadas==5)
            {
                List_Avispas.clear();
                List_moscas.clear();
                return;

            }


     }

FinJuego();

}



void Instrucciones()
{
    int w,h;
    SDL_Texture* background_menu = IMG_LoadTexture(renderer,"Instrucciones.png");
    SDL_QueryTexture(background_menu, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

       { while(true)
    {


        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                 if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_s)
                        {
                            return;
                        }
            }
            }
        }
            SDL_RenderCopy(renderer, background_menu, NULL, &rect_background);
            SDL_RenderPresent(renderer);
     }
}

}

void Menu()
{

    int w,h;
    SDL_Texture* background_menu = IMG_LoadTexture(renderer,"Fondo_Menu.png");
    SDL_QueryTexture(background_menu, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

       { while(true)
    {


        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                 if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_RETURN)
                {
                    Juego();
                }
                if(Event.key.keysym.sym == SDLK_s)
                        {
                            return;
                        }

               if(Event.key.keysym.sym == SDLK_SPACE)
                        {
                            Instrucciones();
                        }
            }
            }
        }
            SDL_RenderCopy(renderer, background_menu, NULL, &rect_background);
            SDL_RenderPresent(renderer);
     }
}

}

int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 971/*WIDTH*/, 675/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    if(TTF_Init()==-1)
    {
        return 40;
    }

    Menu();

	return 0;

}
