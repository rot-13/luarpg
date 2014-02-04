#include <stdio.h>
#include "console.h"
#include "log.h"

#include "game_engine.h"
#include "world_picker.h"
#include "room.h"
#include "actions/room_action_handler.h"

#include "styled_text/terminal_renderer.h"
#include "styled_text/text.h"

extern "C" {
    #include "lua5.1/lua.h"
    #include "lua5.1/lualib.h"
    #include "lua5.1/lauxlib.h"
}

using namespace StyledText;

Room room(blank("Starting room"));
Room north(blue("North room"));

void onNorth();

int main(int argc, char* argv[]) {
    Text& node = blank(bold("Welcome to", magenta("Lua", blink("RPG")), "It's pretty"), negative("awesome"));

    std::string str = TerminalRenderer::render(node);

    Console::print(str.c_str());

    room.north = &north;

    RoomActionHandler rah(&room);
    rah.setOnNorth(&onNorth);

    bool running = true;
    Console::print(TerminalRenderer::render(room.description).c_str());
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

    //char* worldFile = nullptr;

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
    Console::print(TerminalRenderer::render(room.north->description).c_str());
}
