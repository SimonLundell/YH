#include <Game.hpp>

// raise your hand once you have this
Game::Game(int width, int height, SDL_Renderer* renderer) :
  width(width),
  height(height),
  renderer(renderer) {
}

SDL_Renderer* Game::get_renderer() {
  return this->renderer;
}

void Game::add(GameObject* obj) {
  this->objects.push_back(obj);
}

/**
 * Loop through all GameObjects and
 * call their update method. */
void Game::update() {
  for (
    std::vector<GameObject*>::iterator it = objects.begin();
    it != objects.end();
    it++
  ) {
    (*it)->update();
  }
}

/**
 * Loop through all GameObjects and
 * call their draw method. */
void Game::draw() {
  for (
    std::vector<GameObject*>::iterator it = objects.begin();
    it != objects.end();
    it++
  ) {
    (*it)->draw();
  }
}