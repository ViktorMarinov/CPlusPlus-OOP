#include "Train.h"
#include "Ticket.h"
#include "GroupTicket.h"
#include "StudentTicket.h"
#include <iostream>
using namespace std;


Train::Train(const char* start , const char* end, double price){
	int size = strlen(start) + 1;
	this->start = new char[size];
	strcpy_s(this->start, size, start);

	int size2 = strlen(end) + 1;
	this->end = new char[size];
	strcpy_s(this->end, size2, end);

	this->price = price;
	this->countTickets = 0;
	this->peopleCount = 0;
	for (int i = 0; i < 100; i++){
		this->tickets[i] = NULL;
	}
}

Train::~Train(){
	delete[] start, end;
	for (size_t i = 0; i < countTickets; i++){
		delete this->tickets[i];
	}
}

void Train::buyTicket(bool isStudent, size_t people){
	if (peopleCount + people > 100){
		cout << "Not enough space! " << endl;
		return;
	}
		
	if (isStudent){
		for (size_t i = 0; i < people; i++){
			this->tickets[countTickets++] = new StudentTicket(start, end, price);
		}
		return;
	}
	if (people >= 4){
		this->tickets[countTickets++] = new GroupTicket(start, end, price, people);
	}
	else{
		for (size_t i = 0; i < people; i++){
			this->tickets[countTickets++] = new Ticket(start, end, price);
		}
	}
	peopleCount += people;
}

double Train::calculateProfit(){
	double sum = 0;
	for (size_t i = 0; i < countTickets; i++){
		sum += tickets[i]->getPrice();
	}
	return sum;
}

void Train::printTickets() const{
	for (size_t i = 0; i < countTickets; i++){
		tickets[i]->print();
		cout << endl;
	}
}
