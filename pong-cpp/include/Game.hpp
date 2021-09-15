#ifndef GAME_H
#define GAME_H
#include <vector>
#include <GameObject.hpp>
#include <SDL2/SDL.h>
#include <Keyboard.hpp>
#include <Font.hpp>

typedef enum {
  WIN_PLAYER,
  WIN_ENEMY,
  WIN_NONE
} WinType;

class Game {
  public:
    Game(int width, int height, SDL_Renderer* renderer, Keyboard* keyboard);

    void update();
    void draw();

    int get_width();
    int get_height();
    
    void add(GameObject* obj);
    void remove(GameObject* obj);
    void reset(WinType winner);
    void lock();
    void unlock();

    Keyboard* get_keyboard();
    std::vector<GameObject*> get_game_objects();

    void reset_ball();

    SDL_Renderer* get_renderer();

  private:
    std::vector<GameObject*> objects;
    int width;
    int height;
    SDL_Renderer* renderer;
    Keyboard* keyboard;
    int lock_timer;
    bool is_locked;
    int player_score;
    int enemy_score;
    Font* font_enemy;
    Font* font_player;
};

#endif