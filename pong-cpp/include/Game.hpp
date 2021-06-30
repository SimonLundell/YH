#ifndef GAME_H
#define GAME_H
#include <vector>
#include <GameObject.hpp>
#include <SDL2/SDL.h>

class Game {
  public:
    Game(int width, int height, SDL_Renderer* renderer);

    void update();
    void draw();
    void add(GameObject* obj);

    SDL_Renderer* get_renderer();

  private:
    std::vector<GameObject*> objects;
    int width;
    int height;
    SDL_Renderer* renderer;
};

#endif