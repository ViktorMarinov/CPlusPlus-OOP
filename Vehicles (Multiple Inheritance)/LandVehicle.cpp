#include "LandVehicle.h"


LandVehicle::LandVehicle(const char* model, double height, double weight, double maxSpeed, int horsePowers):Vehicle(model, height, weight){
	this->maxSpeed = maxSpeed;
	this->horsePowers = horsePowers;
}

LandVehicle::LandVehicle(const LandVehicle& other) :Vehicle(other){
	this->maxSpeed = other.maxSpeed;
	this->horsePowers = horsePowers;
}

LandVehicle& LandVehicle::operator=(const LandVehicle& other){
	if (this != &other){
		Vehicle::operator=(other);
		this->maxSpeed = other.maxSpeed;
		this->horsePowers = horsePowers;
	}
	return *this;
}

float LandVehicle::getTime(float km) const{
	return km / maxSpeed;
}