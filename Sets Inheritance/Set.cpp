#include "Set.h"
#include <iostream>
using namespace std;

bool Set::operator*(const Set& other){
	size_t l = other.length();
	for (size_t i = 0; i < l; i++){
		if (!this->member(other[i])) //other.operator[](i)
			return true;
	}
	return false;
}

Set& Set::operator+=(const Set& other){
	size_t l = other.length(); //length е динамична и се извиква според обекта
	for (size_t i = 0; i < l; i++){
		this->insert(other[i]);
	}
	return *this;
}

bool Set::operator<(const Set& other) const{
	size_t l = this->length();
	for (size_t i = 0; i < l; i++){
		if (!other.member(this->operator[](i)))
			return false;
	}
	return true;
}