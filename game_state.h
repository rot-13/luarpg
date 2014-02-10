#ifndef GAME_STATE_H
#define GAME_STATE_H

class GameState {
    public:

    private:
        Player* mPlayer;
        Room* mCurrentRoom;
        std::vector<BaseActionHandler*> mActionHandlers;
};

#endif // GAME_STATE_H
