#include <vector>
#include "readline.h"

class WorldPicker {
    public:
        WorldPicker();
        char* pickWorld();

    private:
        std::vector<char*> listWorlds(const char* worldFolder);
};
