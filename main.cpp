#include <stdio.h>
#include "console.h"
#include "log.h"

#include "game_engine.h"
#include "world_picker.h"
#include "room.h"
#include "actions/room_action_handler.h"

extern "C" {
    #include "lua5.1/lua.h"
    #include "lua5.1/lualib.h"
    #include "lua5.1/lauxlib.h"
}

Room room("Starting room");
Room north("North room");

void onNorth();

int main(int argc, char* argv[]) {

    room.north = &north;

    RoomActionHandler rah(&room);
    rah.setOnNorth(&onNorth);

    bool running = true;
    Console::print(room.description);
    while (running) {
        char* input = Console::read("> ");
        if (strcmp(input, "exit") == 0) {
            return 0;
        }
        if (strcmp(input, "list") == 0) {
            std::vector<const char*> list = rah.getActions();
            for (int i = 0; i < list.size(); ++i) {
                Console::print(list[i]);
            }
        }
        rah.runAction(input);
    }

    //char* worldFile = NULL;

    //if (argc > 1) {
        //worldFile = argv[1];
    //} else {
        //WorldPicker worldPicker;
        //worldFile = worldPicker.pickWorld();
    //}

    //GameEngine game;
    //game.runWorld(worldFile);

    //Console::print("\n\n\x1b[31mGame Over\x1b[0m");

    return 0;
}

void onNorth() {
    Console::print(room.north->description);
}
