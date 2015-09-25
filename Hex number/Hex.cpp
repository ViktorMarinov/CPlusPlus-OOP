#include "Hex.h"
#include <iostream>
using namespace std;
enum hex{ A = 10, B, C, D, E, F };


char convertToChar(int number){
	if (number >= 0 && number <= 9)
		return '0' + number;
	else
		return 'A' + number % 10;
}
void reverseString(char* str){
	int size = strlen(str);
	for (int i = 0; i < size / 2; i++)
	{
		char tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
	}
}

int convertToInt(char ch){
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	else
		return ch - 'A' + 10;
}

//void convertToHex(char* str, int number){
//	int count = 0;
//	int number1 = number;
//	while (number1){
//		number1 /= 16;
//		count++;
//	}
//	delete[] str;
//	str = new char[count + 1];
//
//	int i = 0;
//	while (number){
//		str[i] = convertToChar(number % 16);
//		number /= 16;
//		i++;
//	}
//	str[count] = '\0';
//}

int convertToNum(char* str1){
	int sum = 0;
	int size = strlen(str1);

	char* str = new char[size + 1];
	strcpy_s(str, size + 1, str1);
	reverseString(str);

	for (int i = 0; i < size; i++){
		sum += convertToInt(str[size - 1 - i]) * pow(16, i);
	}
	return sum;
}

Hex::Hex(int number):number(nullptr) {
	int count = 0;
	int number1 = number;
	while (number1){
		number1 /= 16;
		count++;
	}
	this->number = new char[count + 1];

	int i = 0;
	while (number){
		this->number[i] = convertToChar(number % 16);
		number /= 16;
		i++;
	}
	this->number[count] = '\0';
}

void Hex::setHex(char* number){
	int size = strlen(number) + 1;
	this->number = new char[size];
	strcpy_s(this->number, size, number);
}

Hex::Hex(char* number):number(nullptr){
	delete[] this->number;

	int size = strlen(number) + 1;
	this->number = new char[size];
	char* temp = new char[size];
	strcpy_s(temp, size, number);

	reverseString(temp);
	strcpy_s(this->number, size, temp);

	delete[] temp;
}

Hex::~Hex(){
	delete[] this->number;
}

Hex::Hex(const Hex& other){
	setHex(other.number);
}

Hex& Hex::operator=(const Hex& right){
	if (this != &right){
		delete[] this->number;
		setHex(right.number);
	}
	return *this;
}

void Hex::print(){
	int size = strlen(number) + 1;
	char* temp = new char[size];
	strcpy_s(temp, size, number);
	reverseString(temp);

	cout << temp << endl;
}

Hex& Hex::operator+=(const Hex& right){
	int sum = convertToNum(this->number) + convertToNum(right.number);
	*this = Hex(sum);
	return *this;
}

Hex Hex::operator+(const Hex& right) const{
	Hex res(*this);
	res += right;
	return res;
}

Hex Hex::operator-(const Hex& right) const{
	Hex res;
	int sum = convertToNum(this->number) - convertToNum(right.number);
	res = Hex(sum);
	return res;
}

Hex Hex::operator*(const Hex& right) const{
	Hex res;
	int sum = convertToNum(this->number) * convertToNum(right.number);
	res = Hex(sum);
	return res;
}

Hex Hex::operator/(const Hex& right) const{
	Hex res;
	if (convertToNum(right.number) != 0){
		int sum = convertToNum(this->number) / convertToNum(right.number);
		res = Hex(sum);
		return res;
	}
	else
		return Hex(0);
}

bool Hex::operator<(const Hex& right) const{
	return convertToNum(this->number) < convertToNum(right.number);
}

bool Hex::operator>(const Hex& right) const{
	return convertToNum(this->number) > convertToNum(right.number);
}

bool Hex::operator>=(const Hex& right) const{
	return !(*this < right);
}

bool Hex::operator<=(const Hex& right) const{
	return !(*this > right);
}

bool Hex::operator==(const Hex& right) const{
	return convertToNum(this->number) == convertToNum(right.number);
}

bool Hex::operator!=(const Hex& right) const{
	return !(*this == right);
}