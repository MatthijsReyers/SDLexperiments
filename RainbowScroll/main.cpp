
#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, const char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
    SDL_Window* window = SDL_CreateWindow(
        "Scroll on the window to see a rainbow", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 
        720, 420, 
        SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;
    
    int step = 0;
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

                case SDL_MOUSEWHEEL:
                    if (event.wheel.y > 0) 
                        step++;
                    else if (event.wheel.y < 0)
                        step = step + 256*3 - 1;
                    if (step >= 256*3) step = step - (256*3);
            }

            // Update background color.
            Uint8 red = (step >= 512) ? Uint8(0) : ((step <= 255) ? Uint8(step) : Uint8(511 - step));
            Uint8 green = (step < 256) ? Uint8(0) : ((step - 255 > 256) ? Uint8(255 - step) : Uint8(step - 512));
            Uint8 blue = (step > 255 && step < 512) ? Uint8(0) : ((step < 256) ? Uint8(255-step) : Uint8(step - 512));
            SDL_SetRenderDrawColor(renderer, red, green, blue, 255);

            // Clear scene
            SDL_RenderClear(renderer);

            //Render the scene
            SDL_RenderPresent(renderer);
        }
        
        SDL_Delay(10);
    }

    SDL_DestroyWindow(window);
}
