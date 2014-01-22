#include "base_action_handler.h"
#include "../room.h"

typedef void (*OnNorthCallback)();

class RoomActionHandler: public BaseActionHandler {
    public:
        RoomActionHandler(Room* room);
        virtual std::vector<const char*> getActions();
        virtual void runAction(const char* action);
        void setOnNorth(OnNorthCallback callback);
        static const char* ACTION_NORTH;
        static const char* ACTION_SOUTH;
        static const char* ACTION_WEST;
        static const char* ACTION_EAST;

    private:
        OnNorthCallback mOnNorthCallback;
        Room* mRoom;
};
