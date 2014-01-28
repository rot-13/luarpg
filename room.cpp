#include <stdio.h>
#include "room.h"

Room::Room(const StyledText::Text& description) : description(description) {
    this->north = NULL;
    this->east = NULL;
    this->south = NULL;
    this->west = NULL;
}
