#include<iostream>
//#include"Clock.h"
#include "Point.h"
#include"Line.h"
using namespace std;

// ���ô���
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

// ��������
int SumOfSquare(int a, int b) {
	return a * a + b * b;
}

double SumOfSquare(double a, double b) {
	return a * a + b * b;
}

double max1(double x, double y) {// �������ȽϷ���
	if (abs(x - y) < 1e-10) return x;// �жϸ��������
	if (x >= y)
		return x;
	else
		return y;
}

// ���ƹ��캯��
void fun1(Point p) {
	cout << p.getX() << endl;
}

Point fun2() {
	Point a;
	return a;
}

int main()
{
	cout << "Hello World!" << endl;

	// ���ô���
	/*int x = 5, y = 10;
	swap(x, y);
	cout << "x=" << x << "y=" << y << endl;*/

	// ��������
	/*int m, n;
	cout << "enter two integer: ";
	cin >> m >> n;
	cout << "Sum of square: " << SumOfSquare(m, n) << endl;
	double x, y;
	cout << "enter two number: ";
	cin >> x >> y;
	cout << "Sum of square: " << SumOfSquare(x, y) << endl;*/

	// ���������
	//Clock c(0, 0, 0); //�Զ����ù��캯��
	//c.showTime();

	// ���ƹ��캯��
	/*Point a;
	Point b(a);
	cout << b.getX() << endl;
	fun1(b);
	b = fun2();
	cout << b.getX() << endl;*/

	// �����
	Point p1(1, 1), p2(4, 5);
	Line line(p1, p2);
	Line line2(line);
	cout << "line length: " <<line.getLen()<< endl;
	cout << "line2 length: " << line2.getLen() << endl;

	return 0;
}