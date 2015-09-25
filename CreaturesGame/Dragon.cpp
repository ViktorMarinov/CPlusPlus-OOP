#include "Dragon.h"


Dragon::Dragon(double health, double mana, double damage, double flyHeight, int numberOfWings, double temperature, Color color, double armor)
	: Creature(health + 1.5*armor, mana, damage * numberOfWings),
	FlyingCreature(health + 1.5*armor, mana, damage * numberOfWings, flyHeight, numberOfWings),
	FlameBreathing(health + 1.5*armor, mana, damage, temperature)
{
	this->color = color;
	if (color == Black)
		this->damage += 10;
	else if (color == White)
		this->health += 10;
	else
		this->mana += 10;
	this->armor = armor;
}

void Dragon::attack(Creature& other){
	breatheIn();
	fly();
	dealDamage(other);
	stopFly();
	breatheOut();
}

double Dragon::getDamage(){
	return FlyingCreature::getDamage() * FlameBreathing::getDamage() / this->damage;
}