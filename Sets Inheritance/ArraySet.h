#pragma once
#include "Set.h"
class ArraySet :public Set{
private:
	int* elements;
	size_t size,
		capacity;
public:
	ArraySet(size_t cap) :capacity(cap), size(0){
		elements = new int[cap];
	}
	~ArraySet(){
		delete[] this->elements;
	}

	virtual bool member(int x) const;
	virtual int operator[](size_t) const;
	virtual bool insert(int x);
	virtual size_t length() const;
	virtual void print() const;
};

