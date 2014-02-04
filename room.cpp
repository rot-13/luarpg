#include <stdio.h>
#include "room.h"

Room::Room(const StyledText::Text& description) : description(description) {
    this->north = nullptr;
    this->east = nullptr;
    this->south = nullptr;
    this->west = nullptr;
}
