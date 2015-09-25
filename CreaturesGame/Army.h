#ifndef ARMY_H
#define ARMY_H
#include "Creature.h"

class Army{
private:
	Creature** arr;
	int size;
public:
	Army();
	~Army();

	void add(Creature&);
	Creature& remove();
	void buffArmy();
	bool battle(Army& defender);
};

#endif