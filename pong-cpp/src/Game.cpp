#include "Game.hpp"

Game::Game(int width, int height) : width(width), height(height) {}


// Loop through all gameobject and call their update method
void Game::Update() 
{
    for (std::vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); it++) 
    {
        (*it)->Update();
    }
}

// Loop through all gameobject and call their draw method
void Game::Draw() 
{
    for (std::vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); it++) 
    {
        (*it)->Draw();
    }
}

void Game::Add(GameObject* obj) 
{
    this->objects.push_back(obj);
}