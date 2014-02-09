#ifndef PLAYER_H_
#define PLAYER_H_

#include "attack_result.h"

class Player {
    public:
        Player();

        AttackResult attack();
        AttackResult takeDamage(Damage damage);
};

#endif // PLAYER_H_
