#ifndef GAME_H
#define GAME_H

#include <vector>

#include "GameObject.hpp"

class Game {
    public:
        Game(int width, int height);

        void Update();
        void Draw();
        void Add(GameObject* obj);

    private:
        std::vector<GameObject*> objects{};
        int width{};
        int height{};

};
#endif