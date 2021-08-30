#ifndef GAME_H
#define GAME_H
#include <vector>
#include <GameObject.hpp>
#include <SDL2/SDL.h>
#include <Keyboard.hpp>

class Game {
  public:
    Game(int width, int height, SDL_Renderer* renderer, Keyboard* keyboard);

    void update();
    void draw();

    int get_width();
    int get_height();
    
    void add(GameObject* obj);

    Keyboard* get_keyboard();

    SDL_Renderer* get_renderer();

  private:
    std::vector<GameObject*> objects;
    int width;
    int height;
    SDL_Renderer* renderer;
    Keyboard* keyboard;
};

#endif