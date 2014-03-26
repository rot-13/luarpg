#ifndef GAME_STATE_H
#define GAME_STATE_H

class GameState {
    public:
        GameState();

    private:
        Player& mPlayer;
        Room& mCurrentRoom;
};

#endif // GAME_STATE_H
