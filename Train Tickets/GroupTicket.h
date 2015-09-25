#ifndef GROUPTICKET_H
#define GROUPTICKET_H

#include "Ticket.h"
#include <iostream>
using namespace std;

class GroupTicket :public Ticket{
	size_t numberOfPeople;
public:
	GroupTicket(const char* start = "", const char* end = "", double price = 0, size_t people = 1) :Ticket(start, end, price){
		numberOfPeople = people;
	}
	//~GroupTicket();

	virtual double getPrice() const{
		double singlePrice = (Ticket::getPrice() * 7) / 10;
		return numberOfPeople*singlePrice;
	}
	virtual size_t countPeople(){ return numberOfPeople; }
	virtual void print() const{
		Ticket::print();
		cout << "  People: " << numberOfPeople;
	}
};

#endif

