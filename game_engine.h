#ifndef GAME_ENGINE_H_
#define GAME_ENGINE_H_

#include <string>
#include "lua.h"

class GameEngine {
    public:
        GameEngine();
        void runWorld(const char* worldFile);

    private:
        std::string getInput() const;
        void handleInput(const std::string input);
        void initLua();
        void closeLua();

        lua_State* mLuaState;
        bool mRunning;
};

#endif // GAME_ENGINE_H_
