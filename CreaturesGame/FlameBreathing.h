#ifndef FLAMEBREATHING_H
#define FLAMEBREATHING_H
#include "Creature.h"
class FlameBreathing :virtual public Creature{
private:
	double temperature;
	bool boost;
public:
	FlameBreathing(double = 0, double = 0, double = 0, double = 0);
	void breatheIn();
	void breatheOut();

	virtual double getDamage();
	virtual void attack(Creature& other);
	virtual Creature* clone(){
		return new FlameBreathing(*this);
	}
	virtual Creature& clone2(){
		return FlameBreathing(*this);
	}
};

#endif