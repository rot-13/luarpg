#include "room_action_handler.h"
#include <cstring>

const char* RoomActionHandler::ACTION_NORTH = "go north";
const char* RoomActionHandler::ACTION_SOUTH = "go south";
const char* RoomActionHandler::ACTION_WEST = "go west";
const char* RoomActionHandler::ACTION_EAST = "go east";

RoomActionHandler::RoomActionHandler(Room* room) {
    mRoom = room;
}

std::vector<const char*> RoomActionHandler::getActions() {
    std::vector<const char*> list;

    if (mRoom->north) {
        list.push_back(ACTION_NORTH);
    }

    if (mRoom->south) {
        list.push_back(ACTION_SOUTH);
    }

    if (mRoom->west) {
        list.push_back(ACTION_WEST);
    }

    if (mRoom->east) {
        list.push_back(ACTION_EAST);
    }

    return list;
}

void RoomActionHandler::runAction(const char* action) {
    if (strcmp(action, ACTION_NORTH) == 0) {
        if (mOnNorthCallback) {
            mOnNorthCallback();
        }
    }
}

void RoomActionHandler::setOnNorth(OnNorthCallback callback) {
    mOnNorthCallback = callback;
}
