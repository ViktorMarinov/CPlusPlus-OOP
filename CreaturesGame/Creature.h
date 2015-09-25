#ifndef CREATURE_H
#define CREATURE_H

class Creature{
	friend class Army;
protected:
	double health,
		mana,
		damage;
public:
	Creature(double = 0, double = 0, double = 0);


	bool isDead(){
		return health <= 0;
	}
	void dealDamage(Creature& other);
	virtual void attack(Creature& other) = 0;
	virtual double getDamage() = 0;

	virtual Creature* clone() = 0;
	virtual Creature& clone2() = 0;
};
#endif