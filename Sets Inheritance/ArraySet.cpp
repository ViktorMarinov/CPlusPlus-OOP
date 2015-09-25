#include "ArraySet.h"
#include <iostream>
using namespace std;

bool ArraySet::member(int x) const{
	for (size_t i = 0; i < size; i++){
		if (elements[i] == x)
			return true;
	}
	return false;
}

int ArraySet::operator[](size_t pos) const{
	if (pos >= size)
		return elements[size - 1];
	return elements[pos];
}

bool ArraySet::insert(int x){
	if (size == capacity){
		return false;
	}
	if (member(x))
		return false;
	elements[size++] = x;
	return true;
}

size_t ArraySet::length() const{
	return size;
}

void ArraySet::print() const{
	for (size_t i = 0; i < size; i++){
		cout << elements[i] << " ";
	}
	cout << endl;
}