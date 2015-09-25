#include "Vehicle.h"
#include <iostream>

void Vehicle::setVehicle(const char* model, double height, double weight){
	delete[] this->model;
	size_t size = strlen(model) + 1;
	this->model = new char[size];
	strcpy_s(this->model, size, model);

	this->height = height;
	this->weight = weight;
}
Vehicle::Vehicle(const char* model, double height, double weight) :model(NULL){
	setVehicle(model, height, weight);
}

Vehicle::Vehicle(const Vehicle& other) : model(NULL){
	setVehicle(other.model, other.height, other.weight);
}

Vehicle& Vehicle::operator = (const Vehicle& other){
	if (this != &other)
		setVehicle(other.model, other.height, other.weight);
	return *this;
}
