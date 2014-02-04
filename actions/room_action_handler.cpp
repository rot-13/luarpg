#include "room_action_handler.h"
#include <cstring>

const char* RoomActionHandler::ACTION_NORTH = "go north";
const char* RoomActionHandler::ACTION_SOUTH = "go south";
const char* RoomActionHandler::ACTION_WEST = "go west";
const char* RoomActionHandler::ACTION_EAST = "go east";

RoomActionHandler::RoomActionHandler(Room& room) : BaseActionHandler(room) {
    registerAction(ACTION_NORTH, [this] (Room& room) -> bool {
        return room.north != nullptr;
    }, [this] (Room& room) {
        if (this->mNorthCallback) {
            this->mNorthCallback(room, room.north);
        }
    });

    registerAction(ACTION_SOUTH, [this] (Room& room) -> bool {
        return room.south != nullptr;
    }, [this] (Room &room) {
        if (this->mSouthCallback) {
            this->mSouthCallback(room, room.south);
        }
    });

    registerAction(ACTION_WEST, [this] (Room& room) -> bool {
        return room.west != nullptr;
    }, [this] (Room &room) {
        if (this->mWestCallback) {
            this->mWestCallback(room, room.west);
        }
    });

    registerAction(ACTION_EAST, [this] (Room& room) -> bool {
        return room.east != nullptr;
    }, [this] (Room &room) {
        if (this->mEastCallback) {
            this->mEastCallback(room, room.east);
        }
    });
}

void RoomActionHandler::setNorthCallback(RoomCallback callback) {
    mNorthCallback = callback;
}

void RoomActionHandler::setSouthCallback(RoomCallback callback) {
    mSouthCallback = callback;
}

void RoomActionHandler::setWestCallback(RoomCallback callback) {
    mWestCallback = callback;
}

void RoomActionHandler::setEastCallback(RoomCallback callback) {
    mEastCallback = callback;
}
