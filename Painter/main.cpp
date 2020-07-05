
#include <iostream>
#include <SDL2/SDL.h>

#define WIDTH 720
#define HEIGHT 420

int main(int argc, const char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
    SDL_Window* window = SDL_CreateWindow(
        "Click to paint pixels", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 
        WIDTH, HEIGHT, 
        SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;

    bool canvas[WIDTH][HEIGHT] = {{false}};

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
                    canvas[event.motion.x][event.motion.y] = true;
                    break;

                case SDL_MOUSEMOTION:
                    if (drawing)
                        canvas[event.motion.x][event.motion.y] = true;
                    break;
                    
                case SDL_MOUSEBUTTONUP:
                    drawing = false;
                    break;
            }

            // Update background color.
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);

            for (int x = 0; x < WIDTH; x++)
                for (int y = 0; y < HEIGHT; y++)
                {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    if (canvas[x][y])
                        SDL_RenderDrawPoint(renderer, x, y);
                }

            //Render the scene
            SDL_RenderPresent(renderer);
        }
        
        SDL_Delay(10);
    }

    SDL_DestroyWindow(window);
}
