#include<iostream>
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


	return 0;
}