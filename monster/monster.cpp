#include "monster.h"

void Monster::init() {
    this.health = 50;
}

Stats Monster::getStats() {
    Stats stats;
    stats.insert(Stat("health", this.health));
    return stats;
}

std::string Monster::getDescription() {
    return "Large monster";
}

AttackResult Monster::attack() {
    return { 10, "The monster farts in your general direction" };
}

AttackResult Monster::takeDamage(Damage damage) {
    if (damage > this.health) {
        damage = this.health;
        this.health = 0;
    } else {
        this.health -= damage;
    }
    return { damage, std::string("The monster takes ") << damage << " points of damage" };
}
