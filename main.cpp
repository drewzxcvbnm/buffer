#include <iostream>
#include "SDL.h"
#include <unistd.h>
using namespace std;

class SDLApp {
public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDLApp(){
        if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) {
            cout<<"Could not initialize SDL:"<< SDL_GetError()<<endl;
            exit(-1);
        }
    }

    void main(){
        window=SDL_CreateWindow("Test Window",90,90,300,300,SDL_WINDOW_SHOWN);
        renderer=SDL_CreateRenderer(window,-1,0);
        SDL_SetRenderDrawColor(renderer,90,90,90,0);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    ~SDLApp(){
        SDL_Quit();
    }
};


int main()
{
    SDLApp *app=new SDLApp();
    app->main();
    while(true) usleep(1000);
    delete app;
    return 0;
}
