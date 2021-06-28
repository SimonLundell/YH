#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject {
    public:
        GameObject(float x, float y);

        void Update();
        void Draw();

    private:
        float x{};
        float y{};
        float height{};
        float width{};
};

#endif