#ifndef TRAIN_H
#define TRAIN_H
#include "Ticket.h"
#include <iostream>

class Train{
private:
	Ticket* tickets[100];
	size_t countTickets;
	size_t peopleCount;

	char* start;
	char* end;
	double price;

public:
	Train(const char*, const char*, double);
	~Train();

	void buyTicket(bool isStudent = false, size_t people = 1); //добавя билет към масива на влака;
	double calculateProfit();
	void printTickets() const;
};

#endif
