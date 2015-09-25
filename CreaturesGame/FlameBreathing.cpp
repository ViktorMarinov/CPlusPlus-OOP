#include "FlameBreathing.h"


FlameBreathing::FlameBreathing(double health, double mana, double damage, double temperature) :Creature(health, mana, damage){
	this->temperature = temperature;
	boost = false;
}

double FlameBreathing::getDamage(){
	if (boost)
		return	temperature * damage;
	else
		return damage;
}

void FlameBreathing::breatheIn(){
	if (mana >= 50){
		boost = true;
		mana -= 50;
	}
}

void FlameBreathing::breatheOut(){
	boost = false;
}

void FlameBreathing::attack(Creature& other){
	breatheIn();
	dealDamage(other);
	breatheOut();
}

