#include <stdio.h>
#include "room.h"

Room::Room(const char* description) {
    this->description = description;
    this->north = NULL;
    this->east = NULL;
    this->south = NULL;
    this->west = NULL;
}
