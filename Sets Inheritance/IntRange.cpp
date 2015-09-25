#include "IntRange.h"
#include <iostream>
using namespace std;


IntRange::IntRange(int start, int end){
	this->start = start;
	this->end = end;
}

int IntRange::operator[](size_t pos) const{
	return start + pos;
}

bool IntRange::insert(int x){
	if (x < start)
		start = x;
	if (x > end)
		end = x;
	return true;
}

size_t IntRange::length() const{
	return end - start + 1;
}

void IntRange::print() const{
	for (size_t i = start; i <= end; i++){
		cout << i << " ";
	}
	cout << endl;
}


