#ifndef LUA_STYLED_TEXT_H_
#define LUA_STYLED_TEXT_H_

#include "../styled_text/text.h"
#include "../lua.h"

namespace Lua {
    class Text {
        public:
            static StyledText::Text* fromLuaState(lua_State* state, int idx);

        private:
            static StyledText::Text& wrapInStyle(StyledText::Text&, const char*);
    };
}

#endif // LUA_STYLED_TEXT_H_
