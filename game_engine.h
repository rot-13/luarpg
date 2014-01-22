#ifndef GAME_ENGINE_H_
#define GAME_ENGINE_H_

extern "C" {
    #include "lua5.1/lua.h"
    #include "lua5.1/lualib.h"
    #include "lua5.1/lauxlib.h"
}

class GameEngine {
    public:
        GameEngine();
        void runWorld(const char* worldFile);

    private:
        void handleInput(const char* input);
        void initLua();
        void closeLua();

        lua_State* mLuaState;
        bool mRunning;
};

#endif // GAME_ENGINE_H_
