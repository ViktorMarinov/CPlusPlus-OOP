#ifndef String_h
#define String_h
class String
{
private:
	char* data;
	void setData(const char*);
public:
	String(const char* = "");
	~String();
	String(const String&);
	String& operator=(const String&);
	String& operator=(const char*);
	void print() const;
	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	bool operator>(const String&) const;
	bool operator>=(const String&) const;
	bool operator<(const String&) const;
	bool operator<=(const String&) const;
	bool operator!() const;
	const String operator+(const String&) const;
	String& operator+=(const String&);
	char& operator[](size_t);
	String operator()(size_t, size_t) const;
};
#endif
