#include "vect2.hpp"
#include <iostream>

vect2::vect2() : x(0), y(0) {}
vect2::vect2(int a, int b) : x(a), y(b) {}
vect2::vect2(const vect2& other) : x(other[0]), y(other[1]) {}
vect2& vect2::operator=(const vect2& other) {
	if (this != &other) {
		x = other[0];
		y = other[1];
	}
	return *this;
}
vect2::~vect2() {}

int& vect2::operator[](int i) {
	if (!i)
		return x;
	return y;
}

int vect2::operator[](int i) const {
	if (!i)
		return x;
	return y;
}

vect2& vect2::operator++() {
	x++;
	y++;
	return *this;
}

vect2 vect2::operator++(int) {
	vect2 res(x++, y++);
	return res;
}

vect2& vect2::operator--() {
	x--;
	y--;
	return *this;
}

vect2 vect2::operator--(int) {
	vect2 res(x--, y--);
	return res;
}

vect2& vect2::operator+=(const vect2& o) {
	x += o[0];
	y += o[1];
	return *this;
}

vect2& vect2::operator-=(const vect2& o) {
	x -= o[0];
	y -= o[1];
	return *this;
}

vect2& vect2::operator*=(int o) {
	x *= o;
	y *= o;
	return *this;
}

vect2 vect2::operator+(const vect2& o) const {
	vect2 res(x + o[0], y + o[1]);
	return res;
}

vect2 vect2::operator-(const vect2& o) const {
	vect2 res(x - o[0], y - o[1]);
	return res;
}

vect2 vect2::operator*(int o) const {
	vect2 res(x * o, y * o);
	return res;
}

vect2& vect2::operator-() {
	x = -x;
	y = -y;
	return *this;
}

bool vect2::operator==(const vect2& o) const {
	return x == o[0] && y == o[1];
}

bool vect2::operator!=(const vect2& o) const {
	return !(*this == o);
}

vect2 operator*(int o, const vect2& vec) {
	vect2 res(o * vec[0], o * vec[1]);
	return res;
}

std::ostream& operator<<(std::ostream& os, const vect2& vec) {
	os << "{" << vec[0] << ", " << vec[1] << "}";
	return os;
}
