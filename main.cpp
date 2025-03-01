#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "SDL2/RenderWindow.hpp"
#include "SDL2/Entity.hpp"

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_INIT_VIDEO failed. Error: " << SDL_GetError() << std::endl;

    if (!IMG_Init(IMG_INIT_PNG))
        std::cout << "IMG_INIT failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window("GAME v1.0.0", 1280, 540);

    SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

    Entity platform0(200, 300, grassTexture);
    Entity platform1(110, 310, grassTexture);

    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }
        window.clear();
        window.render(platform0);
        window.render(platform1);
        window.display();
    }
    window.cleanUp();
    SDL_Quit();

    return 0;
}