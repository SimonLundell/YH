#include <stdio.h>
#include <SDL2/SDL.h>

// raise your hand if you're seeing a window

int main(int argc, char* argv[])
{
  SDL_Window *win = NULL;
  SDL_Renderer *renderer = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Error!\n");
    return 1;
  }

  // create window
  win = SDL_CreateWindow("Pong", 0, 0, 640, 480, 0);

  // create renderer
  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

  while (true) {

    // looking for user input
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        break;
    }

    // update the graphics
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

  }

  // destroying the window and the reference to the renderer
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);

  return 0;
}


// cmake . -G "Unix Makefiles"
// make
// ./pong
