#ifndef ROOM_H_
#define ROOM_H_

#include "styled_text/text.h"
#include "monster/monster.h"

class Room {
    public:
        Room(const StyledText::Text& description);

        Room* north;
        Room* south;
        Room* west;
        Room* east;

        const StyledText::Text& description;
};

#endif // ROOM_H_
