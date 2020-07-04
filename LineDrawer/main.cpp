
#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, const char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
    SDL_Window* window = SDL_CreateWindow(
        "Click and drag to draw a line", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 
        720, 420, 
        SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event event;
    int x0, y0, x1, y1;
    bool quit = false, drawing = false;
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
                    drawing = true;
                    x0 = event.motion.x;
                    y0 = event.motion.y;

                case SDL_MOUSEMOTION:
                    if (drawing) {
                        x1 = event.motion.x;
                        y1 = event.motion.y;
                    } break;
                    
                case SDL_MOUSEBUTTONUP:
                    drawing = false;
            }

            // Update background color.
            SDL_SetRenderDrawColor(renderer, 10, 25, 5, 255);
            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer, 0, 255, 10, 255);
            SDL_RenderDrawLine(renderer, x0, y0, x1, y1);

            //Render the scene
            SDL_RenderPresent(renderer);
        }
        
        SDL_Delay(10);
    }

    SDL_DestroyWindow(window);
}
