#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H
#include <stdio.h>
#include <Game.hpp>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#include <libloaderapi.h>
#else
#include <dlfcn.h>
#endif

typedef void (*plugin_game_init(Game* game))();

#ifdef _WIN32
typedef HINSTANCE Handle;
#else
typedef void* Handle;
#endif

class Plugin
{
    public:
        Plugin(Handle handle);

        void game_init(Game* game);
    
    private:
        Handle handle;
};

class PluginManager 
{
    public:
        PluginManager(const char* plugin_dir);

        void load_plugins();
        void call_plugins(Game* game);

    private:
        char* plugin_dir;
        std::vector<Plugin*> plugins;
};

#endif