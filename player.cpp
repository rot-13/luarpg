#include "player.h"

Player::Player() {
    //mEquippedWeapon = nullptr;
}

//AttackResult Player::attack(Attackable& target) {
    //if (mEquippedWeapon) {
        //return mEquippedWeapon.attack(target);
    //} else {
        //return target.takeDamage(5);
    //}
//}

//void Player::use(Usable& item) {
    //item.use(this);
//}

//void Player::open(Openable& container) {
    //container.open(this);
//}

//void Player::unlock(Unlockable& lock) {
    //lock.unlock(this);
//}

StyledText::Text& Player::examine(Entity& object) {
    return object.describe();
}

//AttackResult Player::takeDamage(Damage damage) {
    //AttackResult attackResult;
    //attackResult.damage = damage;
    //attackResult.attackText = StyledText::text("You take ", StyledText::bold(String::make(damage)), " points of damage");
//}
