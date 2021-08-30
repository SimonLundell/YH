#ifndef PONG_KEYBOARD_H
#define PONG_KEYBOARD_H

class Keyboard {
    public:
        bool is_key_pressed(int key);
        void set_key(int key, int toggle);
    
    private:
        int keys[256];
};
#endif