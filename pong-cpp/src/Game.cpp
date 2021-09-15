#include <Game.hpp>
#include <Ball.hpp>

#define LOCK_TIME 1000 / 12

Game::Game(int width, int height, SDL_Renderer* renderer, Keyboard* keyboard) :
  width(width),
  height(height),
  renderer(renderer),
  keyboard(keyboard),
  is_locked(false),
  lock_timer(LOCK_TIME),
  player_score(0),
  enemy_score(0) 
{
  this->font_enemy = 0;
  this->font_player = 0;
}

Keyboard* Game::get_keyboard() {
  return this->keyboard;
}

std::vector<GameObject*> Game::get_game_objects()
{
  return this->objects;
}

SDL_Renderer* Game::get_renderer() {
  return this->renderer;
}

int Game::get_width()
{
  return this->width;
}

int Game::get_height()
{
  return this->height;
}

void Game::reset(WinType winner)
{
  char tmpstr[256];
  
  if (winner == WIN_PLAYER)
  {
    printf("Player won\n");
    this->player_score += 1;

  }
  else if (winner == WIN_ENEMY)
  {
    printf("Enemy won\n");
    this->enemy_score += 1;
  }
  
  if (this->font_player != 0)
  {
    sprintf(tmpstr, "%d", this->player_score);
    this->font_player->set_text(tmpstr, {255,255,255,1});
  }
  
  if (this->font_enemy != 0)
  {
    sprintf(tmpstr, "%d", this->enemy_score);
    this->font_enemy->set_text(tmpstr, {255,255,255,1});
  }
  this->lock();
  this->reset_ball();
}

void Game::lock()
{
  this->lock_timer = LOCK_TIME;
  this->is_locked = true;
}

void Game::unlock()
{
  this->lock_timer = 0;
  this->is_locked = false;
}

void Game::add(GameObject* obj) {
  this->objects.push_back(obj);
}

void Game::remove(GameObject* obj)
{
  int length = this->objects.size();
  std::vector<GameObject*>::iterator begin = this->objects.begin();
  for (int i = 0; i < length; i++)
  {
    GameObject* object = this->objects[i];

    if (object == obj)
    {
      this->objects.erase(begin + i);
      break;
    }
  }
}

void Game::reset_ball()
{
  int length = this->objects.size();
  std::vector<GameObject*>::iterator begin = this->objects.begin();
  Ball* ball = 0;
  for (int i = 0; i < length; i++)
  {
    GameObject* object = this->objects[i];

    if (dynamic_cast<Ball*>(object) != nullptr)
    {
      ball = (Ball*)object;
      break;
    }
  }

  if (ball)
  {
    this->remove(ball);
    delete (Ball*)ball;
  }

this->add(new Ball(this->get_width()/2, this->get_height()/2));
}
/**
 * Loop through all GameObjects and
 * call their update method. */
void Game::update() {
  if (this->lock_timer > 0)
  {
    this->lock_timer -= 1;
  } 
  else 
  {
    for (auto it = objects.begin(); it != objects.end(); it++)
    {
      (*it)->update();
    }
  }
}
/**
 * Loop through all GameObjects and
 * call their draw method. */
void Game::draw() {
  if (this->font_enemy == 0)
  {
    this->font_enemy = new Font("../assets/Ubuntu_Mono/UbuntuMono-Regular.ttf","0",24,{255,255,255,1}); 
  }
  if (this->font_player == 0)
  {
    this->font_player = new Font("../assets/Ubuntu_Mono/UbuntuMono-Regular.ttf","0",24,{255,255,255,1}); 
  }

  for (auto it = objects.begin(); it != objects.end(); it++)
  {
    (*it)->draw();
  }
  
  this->font_enemy->draw(30,30);
  this->font_player->draw(this->get_width()-30, 30);
}