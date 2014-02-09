#include <stdio.h>
#include "console.h"
#include "log.h"

#include "game_engine.h"
#include "world_picker.h"
#include "room.h"
#include "actions/room_action_handler.h"
#include "monster/monster.h"
#include "actions/monster_action_handler.h"

#include "styled_text/terminal_renderer.h"
#include "styled_text/text.h"

extern "C" {
    #include "lua5.1/lua.h"
    #include "lua5.1/lualib.h"
    #include "lua5.1/lauxlib.h"
}

using namespace StyledText;

Room* currentRoom = nullptr;
Room room(text("You find yourself in a dark room. There seems to be light coming from the north exit."));
Room north(red("A dead end."));

RoomActionHandler* rah = nullptr;

void setRoom(Room& nextRoom);

int main(int argc, char* argv[]) {
    room.north = &north;
    north.south = &room;

    Console::print(bold("You wake up..."));

    setRoom(room);

    Monster monster;
    monster.init();

    MonsterActionHandler mah(monster);
    mah.setAttackCallback([] (Monster& monster) {
        AttackResult res = monster.takeDamage(10);
        Console::print(res.attackText);
        if (monster.isAlive()) {
            AttackResult counter = monster.attack();
            Console::print(counter.attackText);
            Console::print(text("You take", red(std::to_string(counter.damage)), "damage"));
        } else {
            Console::print(text("The monster is dead"));
        }
    });

    Console::print(monster.getDescription());

    bool running = true;
    while (running) {
        char* input = Console::read("> ");
        if (strcmp(input, "exit") == 0) {
            return 0;
        }
        if (strcmp(input, "list") == 0) {
            std::vector<const char*> list = mah.getActions();
            for (int i = 0; i < list.size(); ++i) {
                Console::print(list[i]);
            }
        }
        mah.runAction(input);
    }

    return 0;
}

void setRoom(Room& nextRoom) {
    Console::print(nextRoom.description);
    currentRoom = &nextRoom;
    if (rah) {
        delete rah;
    }
    rah = new RoomActionHandler(*currentRoom);
    rah->setNorthCallback([] (Room& room, Room& northRoom) {
        setRoom(northRoom);
    });
    rah->setSouthCallback([] (Room& room, Room& southRoom) {
        setRoom(southRoom);
    });
    rah->setEastCallback([] (Room& room, Room& eastRoom) {
        setRoom(eastRoom);
    });
    rah->setWestCallback([] (Room& room, Room& westRoom) {
        setRoom(westRoom);
    });
}
