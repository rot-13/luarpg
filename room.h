

class Room {
    public:
        Room(const char* description);

        Room* north;
        Room* south;
        Room* west;
        Room* east;

        const char* description;
};