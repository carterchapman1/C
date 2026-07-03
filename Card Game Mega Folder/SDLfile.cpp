#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Header Files/Card.h"
#include "Header Files/Currency.h"
#include "Header Files/Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int SDLStart()
{
     if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          680, 480,
                                          0);



    if(!window)
    {
        std::cout << "Failed to create window\n";
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer)
    {
        std::cout << "Failed to create render\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
        
    
    SDL_Texture* texture = IMG_LoadTexture(renderer, "my_image.png");
    
    if (!texture)
    {
        std::cout << "Failed to load texture: " << IMG_GetError() << "\n";
    }
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                running = false; // Exits the loop safely when you click the X button
            }
        }
    // Clear the screen with a background color (e.g., black)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Copy the texture to the renderer (can specify source and destination rects)
    if (texture)
    {
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    }
    // Present the frame to the window
    SDL_RenderPresent(renderer);
    }

    

    if (texture) SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}