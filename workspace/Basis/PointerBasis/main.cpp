#include<iostream>
using namespace std;

#include"Point.h"
#include"ArrayOfPoint.h"

// ����ת��
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

//
void splitFloat(float x, int *intPart, float *fracPart) {
	*intPart = static_cast<int>(x);
	*fracPart = x - *intPart;
}

// �����ص�
int computer(int a, int b, int(*func)(int, int)) { return func(a, b); }
int max(int a, int b) { return ((a > b) ? a : b); }
int min(int a, int b) { return ((a < b) ? a : b); }
int sum(int a, int b) { return a + b; }

int main() {
	// ����
	/*const char key[] = { 'a', 'c', 'b', 'a', 'd' };
	const int NUM_QUES = 5;
	char c;
	int ques = 0, numCorrect = 0;
	cout << "Enter the" << NUM_QUES << "question test:" << endl;
	while (cin.get(c))
	{
		if (c != '\n') {
			if (c == key[ques]) {
				numCorrect++;
				cout << 'v';
			}
			else cout << "x";
			ques++;
		}else{
			cout << "Score:" << static_cast<float>(numCorrect) / NUM_QUES * 100 << "%" << endl;
			ques = 0; numCorrect = 0;
		}
	}*/

	// ����ת��
	/*int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i; i < 3; i++) {
		for (int j; j < i; j++) {
			swap(a[i][j], a[j][i]);
		}
	}*/

	// �ֽ�������С��
	/*float f = 122.3, y;
	int x;
	splitFloat(f, &x, &y);*/

	// �����ص�
	/*int a, b, res;
	cout << "Enter two number: ";
	cin >> a;
	cin >> b;

	res = computer(a, b, &max);
	cout << "max = " << res << endl;

	res = computer(a, b, &min);
	cout << "min = " << res << endl;

	res = computer(a, b, &sum);
	cout << "sum = " << res << endl;*/


	// ��ά���鶯̬����
	//int(*cp)[9][8] = new int[7][9][8];// cp ��һ��[9][8]�����ͷ
	//for (int i = 0; i < 7; i++)
	//	for (int j = 0; j < 9; j++)
	//		for (int k = 0; k < 8; k++)
	//			*(*(*(cp + i) + j) + k) = (i * 100 + j * 10 + k);
	//for (int i = 0; i < 7; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		for (int k = 0; k < 8; k++)
	//			cout << cp[i][j][k] << "    ";
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	//delete[] cp;


	// ��̬������
	int count;
	cout << "Please enter the count of points:";
	cin >> count;
	ArrayOfPoint points(count);
	points.element(0).move(5, 0);
	points.element(1).move(15, 20);
	

	return 0;
}