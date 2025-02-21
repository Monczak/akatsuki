#include <iostream>
#include <SDL.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <spdlog/spdlog.h>

SDL_Window* window;
SDL_Renderer* renderer;
bool running = true;

void main_loop()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            running = false;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

#ifdef __EMSCRIPTEN__
    if (!running)
        emscripten_cancel_main_loop();
#endif
}

int main()
{
    spdlog::info("Hello World!");

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("akatsuki", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(main_loop, 0, 1);
#else
    while (running)
        main_loop();
#endif

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
