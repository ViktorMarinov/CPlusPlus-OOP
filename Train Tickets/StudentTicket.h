#ifndef STUDENTTICKET_H
#define STUDENTTICKET_H
#include "Ticket.h"
#include <iomanip>

class StudentTicket :public Ticket{
public:
	StudentTicket(const char* start = "", const char* end = "", double price = 0) :Ticket(start, end, price){}
	//~StudentTicket();

	virtual double getPrice() const{ return Ticket::getPrice() / 2; }
	virtual size_t countPeople(){ return 1; }
	virtual void print() const{
		Ticket::print();
	}

};
#endif
