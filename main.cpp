#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<SDL2/SDL_ttf.h>
#include<list>
#include <SDL2/SDL_mixer.h>
#include <fstream>

#include "Pascal.h"
#include "Camaleon.h"
#include "Moscas.h"
#include "Avispas.h"


SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *Fondo;
SDL_Texture *Air;
SDL_Texture *Sun;
SDL_Texture *Sun2;
SDL_Rect rect_Fondo;
SDL_Rect rect_Air;
SDL_Rect rect_Sun;
SDL_Rect rect_Sun2;
SDL_Rect rect_MoscasComidas;
SDL_Rect rect_MoscasPasadas;
SDL_Rect rect_background;

Mix_Music *gMusic = NULL;

using namespace std;

    list<Moscas*>List_moscas;
    list<Avispas*>List_Avispas;

    int MoscasComidas=0;

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

void FinJuego(int Score)
{

string MC= "Total Moscas Comidas " + toString(Score);

    rect_MoscasComidas.x = 300;
    rect_MoscasComidas.y = 170;
    rect_MoscasComidas.w = 350;
    rect_MoscasComidas.h = 50;


SDL_Color Color = {250,0,0};
TTF_Font *Font = TTF_OpenFont("Font.ttf", 300);

SDL_Surface* Temp = TTF_RenderText_Solid(Font,MC.c_str(), Color);
SDL_Texture* Texto = SDL_CreateTextureFromSurface(renderer,  Temp);

            Temp = TTF_RenderText_Solid(Font,MC.c_str(), Color);
            Texto = SDL_CreateTextureFromSurface(renderer, Temp);

            SDL_RenderCopy(renderer, Texto, NULL, &rect_MoscasComidas);

            SDL_FreeSurface(Temp);
            SDL_DestroyTexture(Texto);



int w=0,h=0;
    Fondo = IMG_LoadTexture(renderer,"Perdiste.png");
    SDL_QueryTexture(Fondo, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    ofstream out("Mejores_Scores");
    out<<Score<<endl;
    out.close();

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
                            return;
                        }
                    }
            }
        }
    SDL_RenderCopy(renderer, Fondo, NULL, &rect_background);
    SDL_RenderPresent(renderer);
    return;
    }

}

void Juego()
{

    int MoscasPasadas=0;
    MoscasComidas=0;
    bool Fin = false;

    string MC= "Moscas Comidas " + toString(MoscasComidas);
    string MP= "Moscas Pasadas " + toString(MoscasPasadas);



                            List_Avispas.clear();
                            List_moscas.clear();

    rect_MoscasComidas.x = 20;
    rect_MoscasComidas.y = 20;
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



    rect_Air.x = -100;
    rect_Air.y = 200;
    rect_Air.w = 80;
    rect_Air.h = 40;
    Air = IMG_LoadTexture(renderer,"air1.png");
    SDL_QueryTexture(Air, NULL, NULL, &w, &h);
    int tempAir=0;

    rect_Sun.x = 0;
    rect_Sun.y = 230;
    rect_Sun.w = 50;
    rect_Sun.h = 40;

    rect_Sun2.x = 0;
    rect_Sun2.y = 100;
    rect_Sun2.w = 70;
    rect_Sun2.h = 70;

    Sun  = IMG_LoadTexture(renderer,"sun.png");
    SDL_QueryTexture(Sun, NULL, NULL, &w, &h);




unsigned int frame_anterior = SDL_GetTicks();

    Camaleon camaleon(renderer);

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
                        }
                        if(Event.key.keysym.sym == SDLK_p)
                        {
                            List_Avispas.clear();
                            List_moscas.clear();
                            return;

                        }
                    }
            }
        }


            SDL_RenderCopy(renderer, Fondo, NULL, &rect_background);
                    if(Fin==true)
                    {
                    SDL_DestroyTexture(camaleon.textura);
                    SDL_DestroyTexture(Sun);
                    SDL_DestroyTexture(Air);
                    FinJuego(MoscasComidas);
                    return;
                    }


            SDL_RenderCopy(renderer, Air, NULL, &rect_Air);
            SDL_RenderCopy(renderer, Sun, NULL, &rect_Sun);
            SDL_RenderCopy(renderer, Sun2, NULL, &rect_Sun2);
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

            if(frame%2==0)
            {
            rect_Sun.x-=1;
            rect_Air.x+=1;
            }

            if(frame%7==0)
            {
            rect_Sun2.x+=1;
            }


            if(rect_Air.x>980)
            rect_Air.x = -10;

            if(tempAir>40)
                tempAir=0;

            if(rect_Sun.x<0)
            rect_Sun.x = 940;

            if(rect_Sun2.x>940)
            rect_Sun2.x = 0;



            if (tempAir<10)
            {
                    SDL_DestroyTexture(Air);
                    Air = IMG_LoadTexture(renderer,"Nube1.png");

                    SDL_DestroyTexture(Sun);
                    Sun = IMG_LoadTexture(renderer,"sun.png");

                    SDL_DestroyTexture(Sun2);
                    Sun2 = IMG_LoadTexture(renderer,"sol1.png");
            }
            else if (tempAir<20)
            {
                    SDL_DestroyTexture(Air);
                    Air = IMG_LoadTexture(renderer,"Nube2.png");

                    SDL_DestroyTexture(Sun);
                    Sun = IMG_LoadTexture(renderer,"sun1.png");

                    SDL_DestroyTexture(Sun2);
                    Sun2 = IMG_LoadTexture(renderer,"sol2.png");
            }
            else if (tempAir<30)
            {
                    SDL_DestroyTexture(Air);
                    Air = IMG_LoadTexture(renderer,"Nube3.png");

                    SDL_DestroyTexture(Sun);
                    Sun = IMG_LoadTexture(renderer,"sun2.png");

                    SDL_DestroyTexture(Sun2);
                    Sun2 = IMG_LoadTexture(renderer,"sol3.png");
            }
            else if (tempAir<40)
            {

                    SDL_DestroyTexture(Sun);
                    Sun = IMG_LoadTexture(renderer,"sun3.png");

                    SDL_DestroyTexture(Air);
                    Air = IMG_LoadTexture(renderer,"Nube4.png");

                    SDL_DestroyTexture(Sun2);
                    Sun2 = IMG_LoadTexture(renderer,"sol4.png");
            }


        if(Mix_PlayingMusic()==0)
        {
        Mix_PlayMusic(gMusic,-1);
        }




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
                                      List_Avispas.clear();
                                      List_moscas.clear();
                                      Fin=true;
                                      Fondo = IMG_LoadTexture(renderer,"perdiste.png");
                                      break;
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
                                    List_moscas.erase(i);
                                    MoscasComidas++;

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
            tempAir++;



            if(MoscasPasadas==5)
            {
                List_Avispas.clear();
                List_moscas.clear();
                Fondo = IMG_LoadTexture(renderer,"perdiste.png");
                Fin = true;

            }
     }

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

    if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
     {
     printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", SDL_GetError());
     }
    gMusic=Mix_LoadMUS("Fade.mp3");
    if(gMusic==NULL){
        printf("Error loading: %s\n", Mix_GetError());
    }

    if(TTF_Init()==-1)
    {
        return 40;
    }

    Menu();

	return 0;

}
