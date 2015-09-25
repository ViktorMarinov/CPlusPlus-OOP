#include "Creature.h"


Creature::Creature(double health, double mana, double damage) :health(health), mana(mana), damage(damage){}

void Creature::dealDamage(Creature& other){
	other.health -= this->getDamage();
}

