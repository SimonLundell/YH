#include <iostream>
#include <map>
#include <string>
#include <memory>

class Enemy {
    public:
      Enemy() { std::cout << "IM CONSTRUCTED " << this << std::endl; }
      ~Enemy() { std::cout << "IM DESTRUCTED " << this << std::endl; }
};

Enemy* createEnemy() {
    Enemy* obj = new Enemy();
    return obj; 
}

int main(int argc, char*argv[]) {
    

    for(int i = 0; i < 10; i++) {
        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>();
        std::cout << "Iteration: " << i << "\n";
    }

    std::cout << "Creating enemy 2\n";
    Enemy* enemy2 = createEnemy();
    delete enemy2;

    return 0;
}