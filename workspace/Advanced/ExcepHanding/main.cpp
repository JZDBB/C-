#include <iostream>
using namespace std;

int divide(int x, int y) {
	if (y == 0)
		throw x;
	return x / y;
}

//�������������߳����������������
double area(double a, double b, double c) {
	//�ж������α߳��Ƿ�Ϊ��
	if (a <= 0 || b <= 0 || c <= 0)
		throw invalid_argument("the side length should be positive");
	//�ж����߳��Ƿ��������ǲ���ʽ
	if (a + b <= c || b + c <= a || c + a <= b)
		throw invalid_argument("the side length should fit the triangle inequality");
	//��Heron��ʽ�������������
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {

	// �쳣����
	/*try {
		cout << "5 / 2 = " << divide(5, 2) << endl;
		cout << "8 / 0 = " << divide(8, 0) << endl;
	}
	catch (int e) {
		cout << e << " is divided by zero!" << endl;
	}
	cout << "That is ok." << endl;*/

	// �쳣����Ĺ��������

	double a, b, c;	//���������߳�
	cout << "Please input the side lengths of a triangle: ";
	cin >> a >> b >> c;

	try {
		double s = area(a, b, c);	//���Լ������������
		cout << "Area: " << s << endl;
	}
	catch (exception &e) {
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}