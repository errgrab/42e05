#pragma once
#include <ostream>

class vect2 {
private:
	int x, y;
public:
	vect2();
	vect2(int, int);
	vect2(const vect2&);
	vect2& operator=(const vect2&);
	~vect2();

	int& operator[](int);
	int  operator[](int) const;

	vect2& operator++();
	vect2 operator++(int);

	vect2& operator--();
	vect2 operator--(int);

	vect2& operator+=(const vect2&);
	vect2& operator-=(const vect2&);
	vect2& operator*=(int);

	vect2 operator+(const vect2&) const;
	vect2 operator-(const vect2&) const;
	vect2 operator*(int) const;

	vect2& operator-();

	bool operator==(const vect2&) const;
	bool operator!=(const vect2&) const;
};

vect2 operator*(int, const vect2&);
std::ostream& operator<<(std::ostream&, const vect2&);
