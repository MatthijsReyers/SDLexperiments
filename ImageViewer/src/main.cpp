
#include <iostream>
#include <SDL2/SDL.h>

// #include "files.hpp"

int main(int argc, const char* argv[])
{
    // BmpFile* image;

    // if (argc > 1) image = new BmpFile(argv[1]);
    // else image = new BmpFile("./dep/demo.bmp");

    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
    SDL_Window* window = SDL_CreateWindow(
        "Click and drag to draw a line", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 
        1080, 720,
        SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface* image_surface;

    if (argc > 1) image_surface = SDL_LoadBMP(argv[1]);
    else image_surface = SDL_LoadBMP("./dep/demo.bmp");

    SDL_Texture* image_texture = SDL_CreateTextureFromSurface(renderer, image_surface);

    SDL_Event event;
    int x0, y0;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
					quit = true;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    x0 = event.motion.x;
                    y0 = event.motion.y;
            }

            // Update background color.
            SDL_SetRenderDrawColor(renderer, 10, 25, 5, 255);
            SDL_RenderClear(renderer);

            int w, h;
            SDL_QueryTexture(image_texture, NULL, NULL, &w, &h);
            SDL_Rect dstrect;
            dstrect.x = x0;
            dstrect.y = y0;
            dstrect.w = w;
            dstrect.h = h;
            SDL_RenderCopy(renderer, image_texture, NULL, &dstrect);

            //Render the scene
            SDL_RenderPresent(renderer);
        }
        
        SDL_Delay(10);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(image_texture);
    SDL_FreeSurface(image_surface);
}
