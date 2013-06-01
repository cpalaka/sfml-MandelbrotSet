#include "Complex.h"
#include <iostream>

Complex::Complex() :
	real(0.0),
	imag(0.0)
{}

Complex::Complex(float x, float y) :
	real(x),
	imag(y)
{
}

float Complex::abs_squared()
{
	return real*real + imag*imag;
}

Complex Complex::square()
{
	Complex c;
	c.real = real*real - imag*imag;
	c.imag = 2*real*imag;

	return c;
}

Complex Complex::cube()
{
	Complex c;
	c.real = real*real*real - imag*imag*real - 2*real*imag*imag;
	c.imag = real*real*real*imag - imag*imag*imag + 2*real*real*imag;

	return c;
}

Complex Complex::add(Complex z)
{
	z.real += real;
	z.imag += imag;
	return z;
}

void Complex::print()
{
	std::cout<<"Complex number: "<<real<<" + "<<"i"<<imag<<std::endl;
}