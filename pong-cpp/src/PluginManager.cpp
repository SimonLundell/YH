#include <PluginManager.hpp>
#include <dirent.h>
#include <string>

#ifdef _WIN32
typedef LPCWSTR Platformstring;
typedef LPCSTR Platformstring2;
#else
#include <sys/stat.h>
#include <unistd.h>
typedef const char* Platformstring;
typedef const char* Platformstring2;
#endif

bool dir_exists(Platformstring2 path)
{
    #ifdef _WIN32
        DWORD ftyp = GetFileAttributesA(path);
        if (ftyp == INVALIDA_FILE_ATTRIBUTES)
        {
            printf("Not able to locate %s", path);
            return false;
        }
        if (ftyp & FILE_ATTRIBUTES_DIRECTORY)
            return true;
        
        return false;
    #else
        return (access(path, F_OK) != -1);
    #endif
}

bool is_shared_library(Platformstring2 path)
{
    return strstr(path, ".dll") != 0 || strstr(path, ".so") != 0; 
}

Handle load_library(Platformstring path_to_file)
{
if (!is_shared_library(path_to_file))
{
    printf("%s is not a library. (skipping...)\n", path_to_file);
    return 0;
}

#ifdef _WIN32
    Handle handle = LoadLibrary(path_to_file);
    if (!handle)
    {
        printf("Failed to load %s", path_to_file);
    }
#else
    Handle handle = dlopen(path_to_file, RTLD_NOW | RTLD_GLOBAL);

    if (handle == NULL)
    {
        printf("Failed to load %s\n", path_to_file);
    }
#endif
    return handle;
}

void* load_function(Handle handle, Platformstring2 func_name)
{
    void* ptr = 0;
#ifdef _WIN32
    ptr = GetProcAddress(handle, func_name);
#else
    ptr = dlsym(handle, func_name);
#endif

    if (ptr == NULL)
    {
        printf("Could not load function %s\n", func_name);
    }
}

Plugin::Plugin(Handle handle) : handle(handle)
{

}

void Plugin::game_init(Game* game)
{
    Platformstring2 func_name = "game_init";
    plugin_game_init* func = (plugin_game_init*)load_function(this->handle, func_name);
    if (func == NULL)
    {
        printf("Could not call function %s\n", func_name);
        return;
    }

    func(game);
}

PluginManager::PluginManager(const char* plugin_dir)
{
    if (!dir_exists(plugin_dir))
    {
        printf("Cannot open %s\n", plugin_dir);
        exit(1);
    }
    this->plugin_dir = (char*)calloc(strlen(plugin_dir)+1, sizeof(char));
    strcpy(this->plugin_dir, plugin_dir);
}

void PluginManager::load_plugins()
{
    DIR* dirp = opendir(this->plugin_dir);
    dirent* dp;
    while((dp=readdir(dirp)) != NULL)
    {
        #ifdef _WIN32
        Platformstring plugin_path = (Platformstring)dp->d_name;
        #else
        char* plugin_path = dp->d_name;
        #endif

        Handle handle = load_library(plugin_path);
        if (!handle) 
            continue;

        Plugin* plug =  new Plugin(handle);
        this->plugins.push_back(plug);
        printf("Nice, loaded library: %s", plugin_path);
    }
}

void PluginManager::call_plugins(Game* game)
{
    for (std::vector<Plugin*>::iterator it = this->plugins.begin(); it != this->plugins.end(); it++)
    {
        Plugin* plug = *it;
        plug->game_init(game);
    }
}