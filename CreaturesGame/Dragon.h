#ifndef DRAGON_H
#define DRAGON_H
#include "FlyingCreature.h"
#include "FlameBreathing.h"

enum Color{ Black = 0, White, Grey };

class Dragon : public FlameBreathing, public FlyingCreature{
private:
	Color color;
	double armor;
public:
	Dragon(double = 0, double = 0, double = 0, double = 0, int = 0, double = 0, Color = Black, double = 0);
	
	virtual void attack(Creature& other);
	virtual double getDamage();
	virtual Creature* clone(){
		return new Dragon(*this);
	}
	virtual Creature& clone2(){
		return Dragon(*this);
	}
};

#endif
