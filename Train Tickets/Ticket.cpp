#include "Ticket.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Ticket::setTicket(const char* start, const char* end, double price){
	delete[] this->start;
	delete[] this->end;
	int size1 = strlen(start) + 1;
	int size2 = strlen(end) + 1;
	this->start = new char[size1];
	this->end = new char[size2];
	strcpy_s(this->start, size1, start);
	strcpy_s(this->end, size2, end);

	this->price = (price > 0) ? price : 0;
}
Ticket::Ticket(const char* start, const char* end, double price):start(NULL),end(NULL){
	setTicket(start, end, price);
}

Ticket::~Ticket(){
	delete[] this->start;
	delete[] this->end;
}

Ticket::Ticket(const Ticket& other):start(NULL), end(NULL){
	setTicket(other.start, other.end, other.price);

}

Ticket& Ticket::operator=(const Ticket& other){
	if (this != &other)
		setTicket(other.start, other.end, other.price);
	return *this;
}

void Ticket::print() const{
	cout << "From: " << setw(5) << start << "  To: " << setw(5) << end << "  Price: " << setw(5) << getPrice();
}
