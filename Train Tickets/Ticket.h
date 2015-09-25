#pragma once
class Ticket{
private:
	double price;
	char* start;
	char* end;
	void setTicket(const char*, const char*, double);
public:
	Ticket(const char* = "", const char* = "", double = 0);
	virtual ~Ticket();
	Ticket(const Ticket&);
	Ticket& operator=(const Ticket&);

	virtual double getPrice() const { return price; }
	virtual size_t countPeople(){ return 1; }
	virtual void print() const;
};

