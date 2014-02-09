#include "monster_action_handler.h"

const char* MonsterActionHandler::ACTION_ATTACK = "attack";

MonsterActionHandler::MonsterActionHandler(Monster& monster) : BaseActionHandler(monster) {
    registerAction(ACTION_ATTACK, [this] (const Monster& monster) -> bool {
        return monster.isAlive();
    }, [this] (Monster& monster) {
        if (this->mAttackCallback) {
            this->mAttackCallback(monster);
        }
    });
}

void MonsterActionHandler::setAttackCallback(AttackCallback callback) {
    mAttackCallback = callback;
}
