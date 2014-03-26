#include "text_user_interface.h"
#include "../console.h"

TextUserInterface::TextUserInterface() {
    
}

void TextUserInterface::update(std::vector<StyledText::Text*> actions, GameState& gameState) {
    for (auto iter = actions.begin(); iter != actions.end(); iter++) {
        Console::print(*(*iter));
    }
}
