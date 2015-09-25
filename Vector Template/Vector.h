#ifndef Vector_h
#define Vector_h
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Vector{
private:
	T* arr;
	int size,
		capacity;
	void setVector(T*, int, int);
public:
	Vector(int=1);
	Vector(const Vector<T>&);
	~Vector();
	Vector<T>& operator=(const Vector<T>&);

	void pushBack(const T&);
	T& pop();
	T& popBack();

	void print() const;
};

template <typename T>
void Vector<T>::setVector(T* arr, int size, int capacity){
	this->capacity = (capacity > 0) ? capacity : 1;
	this->size = size;

	delete[] this->arr;
	this->arr = new T[capacity];
	for (int i = 0; i < size; i++){
		this->arr[i] = arr[i];
	}
}

template <typename T>
Vector<T>::Vector(int capacity) :arr(nullptr){
	setVector(nullptr, 0, capacity);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) : arr(nullptr){
	setVector(other.arr, other.size, other.capacity);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& right){
	if (this != &right){
		setVector(right.arr, right.size, right.capacity);
	}
	return *this;
}

template <typename T>
Vector<T>::~Vector(){
	delete[] this->arr;
}

template <typename T>
void Vector<T>::pushBack(const T& newElem){
	if (size == capacity){
		capacity *= 2;
		T* temp = arr;
		this->arr = new T[capacity];
		for (int i = 0; i < size; i++)
			this->arr[i] = temp[i];
		delete[] temp;
	}
	arr[size++] = newElem;
}

template <typename T>
T& Vector<T>::pop(){
	assert(size > 0);
	T res = arr[0];
	for (int i = 0; i < size - 1; i++){
		arr[i] = arr[i + 1];
	}
	size--;
	return res;
}

template <typename T>
T& Vector<T>::popBack(){
	assert(size > 0);
	size--;
	return arr[size];
}

template <typename T>
void Vector<T>::print() const{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}
#endif
