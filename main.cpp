#include <stdio.h>
#include "readline.h"

#include "room.h"
#include "world_picker.h"

extern "C" {
    #include "lua5.1/lua.h"
    #include "lua5.1/lualib.h"
    #include "lua5.1/lauxlib.h"
}

int main(int argc, char* argv[]) {

    lua_State* L;

    L = lua_open();
    luaL_openlibs(L);

    WorldPicker picker;
    char* luaFile = picker.pickWorld();

    printf("Loading file: %s\n", luaFile);

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
