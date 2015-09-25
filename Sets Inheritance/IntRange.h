#pragma once
#include "Set.h"
class IntRange : public Set{
private:
	int start, end;
public:
	IntRange(int, int);

	virtual bool member(int x) const {
		return x >= start && x <= end;
	}
	virtual int operator[](size_t) const;
	virtual bool insert(int x);
	virtual size_t length() const;
	virtual void print() const;

};

