#include "text.h"
#include <cstring>

StyledText::Text* Lua::Text::fromLuaState(lua_State* state, int idx) {
    if (lua_type(state, idx) == LUA_TTABLE) {
        StyledText::Text& text = StyledText::make();
        lua_pushnil(state);
        while (lua_next(state, idx) != 0) {
            const char* key = nullptr;
            if (lua_type(state, -2) == LUA_TSTRING) {
                key = lua_tostring(state, -2);
            }

            int valueIdx = lua_gettop(state);
            StyledText::Text* child = fromLuaState(state, valueIdx);
            lua_pop(state, 1);

            if (child) {
                if (key) {
                    text << wrapInStyle(*child, key);
                } else {
                    text << *child;
                }
            }
        }
        return &text;
    } else if (lua_isstring(state, idx)) {
        return &StyledText::text(lua_tostring(state, idx));
    } else {
        // unsupported value
        return nullptr;
    }
}

StyledText::Text& Lua::Text::wrapInStyle(StyledText::Text& text, const char* styleName) {
    if (strcmp(styleName, "black") == 0) {
        return StyledText::black(text);

    } else if (strcmp(styleName, "red") == 0) {
        return StyledText::red(text);

    } else if (strcmp(styleName, "green") == 0) {
        return StyledText::green(text);

    } else if (strcmp(styleName, "yellow") == 0) {
        return StyledText::yellow(text);

    } else if (strcmp(styleName, "blue") == 0) {
        return StyledText::blue(text);

    } else if (strcmp(styleName, "magenta") == 0) {
        return StyledText::magenta(text);

    } else if (strcmp(styleName, "cyan") == 0) {
        return StyledText::cyan(text);

    } else if (strcmp(styleName, "white") == 0) {
        return StyledText::white(text);

    } else if (strcmp(styleName, "bold") == 0) {
        return StyledText::bold(text);

    } else if (strcmp(styleName, "blink") == 0) {
        return StyledText::blink(text);

    } else if (strcmp(styleName, "underline") == 0) {
        return StyledText::underline(text);

    } else if (strcmp(styleName, "negative") == 0) {
        return StyledText::negative(text);

    } else {
        return text;
    }
}
