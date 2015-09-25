#ifndef SET_H
#define SET_H

class Set{
public:
	virtual ~Set(){}
	virtual bool member(int x) const = 0;
	virtual int operator[](size_t) const = 0;
	virtual size_t length() const = 0;
	virtual bool insert(int x) = 0;
	virtual void print() const = 0;

	bool operator<(const Set&) const;
	bool operator*(const Set&);
	Set& operator+=(const Set&);

};

#endif