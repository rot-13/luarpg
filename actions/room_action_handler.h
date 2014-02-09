#ifndef ROOM_ACTION_HANDLER_H_
#define ROOM_ACTION_HANDLER_H_

#include <functional>
#include "base_action_handler.h"
#include "../room.h"

class RoomActionHandler: public BaseActionHandler<Room> {
    public:
        typedef std::function<void(Room&, Room&)> RoomCallback;

        RoomActionHandler(Room& room);
        void setNorthCallback(RoomCallback);
        void setSouthCallback(RoomCallback);
        void setWestCallback(RoomCallback);
        void setEastCallback(RoomCallback);
        static const char* ACTION_NORTH;
        static const char* ACTION_SOUTH;
        static const char* ACTION_WEST;
        static const char* ACTION_EAST;

    private:
        RoomCallback mNorthCallback;
        RoomCallback mSouthCallback;
        RoomCallback mWestCallback;
        RoomCallback mEastCallback;
};

#endif // ROOM_ACTION_HANDLER_H_
