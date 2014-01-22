#include <dirent.h>
#include <stdlib.h>
#include "world_picker.h"
#include "console.h"
#include "log.h"

WorldPicker::WorldPicker() {
    
}

char* WorldPicker::pickWorld() {
    const char* folder = "./worlds";
    std::vector<char*> worlds = listWorlds(folder);

    for (int i = 0; i < worlds.size(); ++i) {
        Console::print("\x1b[37;1m%d.\x1b[34;1m %s\x1b[0m", i, worlds[i]);
    }

    char* selectionString = Console::read("\x1b[37;1mChoose world\x1b[0m: ");

    int selection = atoi(selectionString);

    Log::debug("You chose: %d. %s", selection, worlds[selection]);

    char* filePath = new char[strlen(folder) + strlen(worlds[selection]) + 1];
    sprintf(filePath, "%s/%s", folder, worlds[selection]);

    return filePath;
}

std::vector<char*> WorldPicker::listWorlds(const char* worldFolder) {
    std::vector<char*> worlds;
    DIR *dir = opendir(worldFolder);
    struct dirent *entry = readdir(dir);

    while (entry != NULL) {
        if (entry->d_type == DT_REG) {
            char* worldName = new char[strlen(entry->d_name)];
            strcpy(worldName, entry->d_name);
            worlds.push_back(worldName);
        }
        entry = readdir(dir);
    }

    closedir(dir);

    return worlds;
}
