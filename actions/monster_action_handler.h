#ifndef MONSTER_ACTION_HANDLER_H_
#define MONSTER_ACTION_HANDLER_H_

#include <functional>
#include "base_action_handler.h"
#include "../monster/monster.h"

class MonsterActionHandler : public BaseActionHandler<Monster> {
    public:
        typedef std::function<void(Monster&)> AttackCallback;

        static const char* ACTION_ATTACK;

        MonsterActionHandler(Monster& monster);
        void setAttackCallback(AttackCallback callback);

    private:
        AttackCallback mAttackCallback;
};

#endif // MONSTER_ACTION_HANDLER_H_
