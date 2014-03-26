#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

class UserInterface {
    public:
        UserInterface(Player& player) : mPlayer(player) {};
        virtual void update(std::vector<StyledText::Text*> actions, GameState& gameState) = 0;

    protected:
        Player& mPlayer;
};

#endif // USER_INTERFACE_H_
