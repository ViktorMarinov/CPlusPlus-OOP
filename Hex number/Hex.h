#ifndef Hex_h
#define Hex_h

class Hex{
private:
	char* number;
	void setHex(char* number);
public:
	Hex(char*);
	Hex(int = 1);
	~Hex();
	Hex(const Hex&);
	Hex& operator=(const Hex&);

	Hex& operator+=(const Hex&);
	Hex operator+(const Hex&) const;
	Hex operator-(const Hex&) const;
	Hex operator*(const Hex&) const;
	Hex operator/(const Hex&) const;

	bool operator!=(const Hex&) const;
	bool operator==(const Hex&) const;
	bool operator<(const Hex&) const;
	bool operator<=(const Hex&) const;
	bool operator>(const Hex&) const;
	bool operator>=(const Hex&) const;

	void print();
};
#endif
