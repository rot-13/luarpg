#include <stdio.h>
#include "console.h"
#include "log.h"

#include "room.h"
#include "world_picker.h"

extern "C" {
    #include "lua5.1/lua.h"
    #include "lua5.1/lualib.h"
    #include "lua5.1/lauxlib.h"
}

int main(int argc, char* argv[]) {

    Log::setLevel(Log::LEVEL_DEBUG);
    lua_State* L;

    L = lua_open();
    luaL_openlibs(L);

    WorldPicker picker;
    char* luaFile = picker.pickWorld();

    Log::debug("Testing");
    Log::info("Loading file: %s", luaFile);
    Log::warn("Testing");
    Log::error("Testing");

    luaL_dofile(L, luaFile);

    //Room exit("You made it to the exit");
    //Room start("Twisty little passages, all alike");
    //start.north = &exit;
    //exit.south = &start;
    //printf("%s\n", start.description);
    //const char* line = readline("What do you do?: ");
    //printf("%s\n", exit.description);
    lua_close(L);
    return 0;
}
