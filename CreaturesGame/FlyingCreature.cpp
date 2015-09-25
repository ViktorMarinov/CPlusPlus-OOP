#include "FlyingCreature.h"


FlyingCreature::FlyingCreature(double health, double mana, double damage, double flyHeight, int numberOfWings) :Creature(health, mana, damage*numberOfWings){
	this->numberOfWings = numberOfWings;
	this->flyHeight = flyHeight;
	this->inAir = false;
}

void FlyingCreature::fly(){
	if (mana >= 20){
		inAir = true;
		mana -= 20;
	}
}

void FlyingCreature::stopFly(){
	inAir = false;
}


void FlyingCreature::attack(Creature& other){
	fly();
	dealDamage(other);
	stopFly();

}

double FlyingCreature::getDamage(){
	if (inAir)
		return this->damage * 0.4 * flyHeight;
	else
		return damage / 2;
}
