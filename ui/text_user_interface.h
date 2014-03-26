#ifndef TEXT_USER_INTERFACE_H_
#define TEXT_USER_INTERFACE_H_

#include <vector>
#include "user_interface.h"
#include "../styled_text/text.h"
#include "../game_state.h"

class TextUserInterface : public UserInterface {
    public:
        TextUserInterface();
        void update(const std::vector<StyledText::Text*> actions, const GameState& gameState);
};

#endif // TEXT_USER_INTERFACE_H_
