#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <memory>
#include <algorithm>
#include "game_engine.h"
#include "log.h"
#include "console.h"
#include "text_input.h"

GameEngine::GameEngine() {
    mLuaState = nullptr;
}

void GameEngine::runWorld(const char* worldFile) {
    initLua();
    mRunning = true;

    while (mRunning) {
        handleInput(getInput());
    }
    closeLua();
}

void GameEngine::handleInput(const std::string inputString) {
    TextInput textInput = TextInput::parseInput(inputString);
    if (textInput.verb.compare("exit") == 0) {
        mRunning = false;
    } else {
        if (textInput.verb.compare("examine") == 0 || textInput.verb.compare("describe") == 0) {
            Entity* ent = findEntity(textInput.params);
            if (ent) {
                //Console::print(mPlayer.examine(ent));
            } else {
                Console::print(StyledText::text("Can't examine unknown object", StyledText::bold(textInput.params)));
            }
        }

        if (textInput.verb.compare("go") == 0) {

        }
    }
}

Entity* GameEngine::findEntity(std::string entityName) {
    if (entityName.compare("room") == 0) {
        //return mCurrentRoom;
    } else {
        // iterate over contents and room and contents of inventory
    }
    return nullptr;
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
