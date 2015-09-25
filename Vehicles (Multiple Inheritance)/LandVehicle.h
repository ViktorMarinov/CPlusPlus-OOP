#ifndef LANDVEHICLE_H
#define LANDVEHICLE_H

#include "Vehicle.h"
class LandVehicle : virtual public Vehicle{
private:
	double maxSpeed;
	int horsePowers;
public:
	LandVehicle(const char* = "", double = 0, double = 0, double = 0, int = 0);
	LandVehicle(const LandVehicle& other);
	LandVehicle& operator=(const LandVehicle& other);
	float getTime(float) const;

	virtual void print(){
		Vehicle::print();
		cout << maxSpeed << " " << horsePowers;
	}
};

#endif