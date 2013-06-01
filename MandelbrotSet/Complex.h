#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>

//a class that holds a complex number and can perform 2 operations:
//the square of the absolute value of the complex number
//and the normal square of the complex number

class Complex {
public:
	Complex();
	Complex(float, float);
	float abs_squared();
	Complex add(Complex);
	Complex square();
	Complex cube();
	void print();

	float real;
	float imag;
private:
};

#endif COMPLEX_H
