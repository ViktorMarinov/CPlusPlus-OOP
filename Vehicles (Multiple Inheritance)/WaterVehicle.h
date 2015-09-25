#pragma once
#include "Vehicle.h"
class WaterVehicle : virtual public Vehicle{
private:
	double displacement;
	double maxSpeed;
public:
	WaterVehicle(const char* = "", double = 0, double = 0, double = 0, double = 0);
	WaterVehicle(const WaterVehicle& other);
	WaterVehicle& operator=(const WaterVehicle& other);

	float getSpeedUpStream(float speedStream) const{
		return maxSpeed - speedStream;
	}
	float getSpeedDownStream(float speedStream) const{
		return maxSpeed + speedStream;
	}
	float getTimeUpStream(float km, float speedStream) const{
		return km / getSpeedUpStream(speedStream);
	}
	float getTimeDownStream(float km, float speedStream) const{
		return km / getSpeedDownStream(speedStream);
	}

	virtual void print(){
		Vehicle::print();
		cout << displacement << " " << maxSpeed;
	}
};

