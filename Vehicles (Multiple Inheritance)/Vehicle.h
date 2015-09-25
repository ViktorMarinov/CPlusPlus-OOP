#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;
class Vehicle{
	char* model;
	double height;
	double weight;
	void setVehicle(const char*, double, double);
public:
	Vehicle(const char* = "", double = 0, double = 0);
	~Vehicle(){ delete[] model; }
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);

	bool canPassUnderBridge(float height) const{
		return (this->height < height);
	}
	bool canPassOverBridge(float weight) const{
		return (this->weight < weight);
	}

	virtual void print(){
		cout << model << " " << height << " " << weight;
	}
};

#endif