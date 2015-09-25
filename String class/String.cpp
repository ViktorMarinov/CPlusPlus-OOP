#include "String.h"
#include <iostream>
#include <cassert>
using namespace std;

void String::setData(const char* newData){
	delete[] this->data;
	size_t length = strlen(newData) + 1; // за '\0'
	this->data = new char[length];
	strcpy_s(this->data, length, newData);
}

String::String(const char* data): data(nullptr){
	this->setData(data);
}

String::~String(){
	delete[] this->data;
}
String::String(const String& other):data(nullptr){
	this->setData(other.data);
}
String& String::operator=(const String& right){
	if (this != &right)
		this->setData(right.data);
	return *this;
}
String& String::operator=(const char* data){
	this->setData(data);
	return *this;
}
void String::print() const{
	cout << data << endl;
}
bool String::operator==(const String& other) const {
	return !(strcmp(this->data, other.data));
}
bool String::operator!=(const String& right) const{
	return !(*this == right);
}
bool String::operator>(const String& right) const{
	return strcmp(this->data, right.data) > 0;
}
bool String::operator>=(const String& right) const{
	return (*this > right) || (*this == right);
}
bool String::operator<(const String& right) const{
	return !(*this >= right);
}
bool String::operator<=(const String& right) const{
	return !(*this > right);
}
String& String::operator+=(const String& right){
	size_t length1 = strlen(this->data);
	size_t length2 = strlen(right.data);
	char* temp = new char[length1 + length2 + 1];
	strcpy_s(temp, length1 + length2 + 1, this->data);
	strcat_s(temp, length2 + length1 + 1, right.data);
	delete[] this->data;
	this->data = temp;
	return *this;
}
const String String::operator+(const String& right) const{
	String res(*this);
	res += right;
	return res;
}
char& String::operator[](size_t index){
	assert(index < strlen(data));
	return data[index];
}
String String::operator()(size_t pos, size_t len) const{
	String res;
	size_t length = strlen(data);
	if (pos >= length)
		return res;
	if (pos + len > length)
		len = length - pos;
	char* temp = new char[len + 1];
	strncpy_s(temp,len + 1, data + pos, len);
	temp[len] = '\0';
	//strcpy_s(temp, len + 1, data + pos);
	res = temp;
	delete[] temp;
	return res;
}
bool String::operator!() const{
	return strlen(data) == 0;
}
