#ifndef ROOM_H_
#define ROOM_H_

class Room {
    public:
        Room(const char* description);

        Room* north;
        Room* south;
        Room* west;
        Room* east;

        const char* description;
};

#endif // ROOM_H_
