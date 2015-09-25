#include "WaterVehicle.h"


WaterVehicle::WaterVehicle(const char* model, double height, double weight, double displacement, double maxSpeed) : Vehicle(model, height, weight){
	this->displacement = displacement;
	this->maxSpeed = maxSpeed;
}

WaterVehicle::WaterVehicle(const WaterVehicle& other) : Vehicle(other){
	this->displacement = other.displacement;
	this->maxSpeed = other.maxSpeed;
}

WaterVehicle& WaterVehicle::operator = (const WaterVehicle& other){
	if (this != &other){
		Vehicle::operator=(other);
		this->displacement = other.displacement;
		this->maxSpeed = other.maxSpeed;
	}
	return *this;
}

