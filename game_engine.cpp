#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "game_engine.h"
#include "log.h"
#include "console.h"

GameEngine::GameEngine() {
    mLuaState = NULL;
}

void GameEngine::runWorld(const char* worldFile) {
    initLua();
    mRunning = true;

    Log::debug("Loading world: \"%s\"", worldFile);
    // TODO: init world

    while (mRunning) {
        char* input = Console::read("> ");
        handleInput(input);
        delete[] input;
    }
    closeLua();
}

void GameEngine::handleInput(const char* input) {
    Log::debug("Got input: \"%s\"", input);
    if (strcmp(input, "exit") == 0) {
        mRunning = false;
    }
}

void GameEngine::initLua() {
    if (mLuaState != NULL) {
        closeLua();
    }
    mLuaState = lua_open();
    luaL_openlibs(mLuaState);
}

void GameEngine::closeLua() {
    if (mLuaState != NULL) {
        lua_close(mLuaState);
        mLuaState = NULL;
    }
}
