#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <memory>
#include <algorithm>
#include "game_engine.h"
#include "log.h"
#include "console.h"

GameEngine::GameEngine() {
    mLuaState = nullptr;
}

void GameEngine::runWorld(const char* worldFile) {
    initLua();
    mRunning = true;

    Log::debug("Loading world: \"%s\"", worldFile);
    // TODO: init world

    while (mRunning) {
        handleInput(getInput());
    }
    closeLua();
}

void GameEngine::handleInput(const std::string input) {
    Log::debug("Got input: \"%s\"", input.c_str());
    if (input.compare("exit") == 0) {
        mRunning = false;
    }
}

void GameEngine::initLua() {
    if (mLuaState) {
        closeLua();
    }
    mLuaState = lua_open();
    luaL_openlibs(mLuaState);
}

void GameEngine::closeLua() {
    if (mLuaState) {
        lua_close(mLuaState);
        mLuaState = nullptr;
    }
}

std::string GameEngine::getInput() const {
    std::shared_ptr<char> input(Console::read("> "));
    std::string inputString = input.get();
    std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
    return inputString;
}
