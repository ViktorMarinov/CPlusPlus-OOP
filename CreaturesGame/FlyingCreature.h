#ifndef FLYINGCREATURE_H
#define FLYINGCREATURE_H
#include "Creature.h"
class FlyingCreature :	virtual public Creature{
private:
	double flyHeight;
	int	numberOfWings;
	bool inAir;
public:
	FlyingCreature(double = 0, double = 0, double = 0, double = 0, int = 0);
	
	void fly();
	void stopFly();
	virtual void attack(Creature& other);
	virtual double getDamage();

	virtual Creature* clone(){
		return new FlyingCreature(*this);
	}
	virtual Creature& clone2(){
		return FlyingCreature(*this);
	}
};

#endif

