#include "Army.h"


Army::Army(){
	this->arr = nullptr;
	this->size = 0;
}

Army::~Army(){
	for (size_t i = 0; i < size; i++)
	{
			delete arr[i];
	}
	delete[] this->arr;
}

void Army::add(Creature& newCreature){
	Creature** temp = arr;
	this->arr = new Creature*[size + 1];
	for (size_t i = 0; i < size; i++){
		this->arr[i] = temp[i];
	}
	delete[] temp;
	this->arr[size++] = newCreature.clone();
}

Creature& Army::remove(){
	Creature& res = arr[0]->clone2();
	delete arr[0];
	for (size_t i = 0; i < size; i++){
		arr[i] = arr[i + 1];
	}
	size--;
	return res;
}

void Army::buffArmy(){
	for (size_t i = 0; i < size; i++){
		this->arr[i]->health += 10;
	}
}

bool Army::battle(Army& defender){
	return true;
}