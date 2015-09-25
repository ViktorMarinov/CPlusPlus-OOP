#pragma once
#include "LandVehicle.h"
#include "WaterVehicle.h"
class AmphibiousVehicle : public LandVehicle, public WaterVehicle{
public:
	AmphibiousVehicle(const char* model, double height, double weight, double maxLandSpeed, int horsePowers, double displacement, double maxWaterSpeed) 
		:Vehicle(model, height, weight), LandVehicle(model, height, weight, maxLandSpeed, horsePowers), WaterVehicle(model, height, weight,displacement, maxWaterSpeed){}
	virtual void print(){
		LandVehicle::print();
		WaterVehicle::print();
	}
};

