#include "vect2.hpp"
#include <iostream>

int main(void) {
	vect2 a;
	vect2 b(1, 2);
	vect2 c(b);
	vect2 d = c;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;

	std::cout << "c++: " << c++ << std::endl;
	std::cout << "++d: " << ++d << std::endl;

	std::cout << "c--: " << c-- << std::endl;
	std::cout << "--d: " << --d << std::endl;

	return 0;
}
