#ifndef WORLD_PICKER_H_
#define WORLD_PICKER_H_

#include <vector>
#include "readline.h"

class WorldPicker {
    public:
        WorldPicker();
        char* pickWorld();

    private:
        std::vector<char*> listWorlds(const char* worldFolder);
};

#endif // WORLD_PICKER_H_
