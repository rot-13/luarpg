#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity/entity.h"
#include "attack_result.h"

class Player {
    public:
        Player();

        //AttackResult attack(Attackable& target);
        //void use(Usable& item);
        //void open(Openable& container);
        //void unlock(Unlockable& lock);
        StyledText::Text& examine(Entity& object);
        //AttackResult takeDamage(Damage damage);

        //void equip(Weapon& weapon);

    private:
        //Weapon* mEquippedWeapon;
};

#endif // PLAYER_H_
