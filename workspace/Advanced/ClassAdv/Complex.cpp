
#include "Complex.h"
#include<iostream>
using namespace std;


Complex::Complex(){}

Complex::Complex(double r = 0.0, double i = 0.0) :real(r), imag(i) {}



Complex::~Complex()
{
}

//Complex Complex::operator + (const Complex &c2) const {
//	return Complex(real + c2.real, imag + c2.imag);
//}
//Complex Complex::operator - (const Complex &c2) const { // ˫Ŀ��������� ����1 operator ����� (����2)
//	return Complex(real - c2.real, imag - c2.imag);
//}
void Complex::display() const {
	cout << "(" << real << "," << imag << ")" << endl;
}

