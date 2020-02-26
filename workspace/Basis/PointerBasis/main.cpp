#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include"Point.h"
#include"ArrayOfPoint.h"
#include"IntNum.h"


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

// �ƶ�����
IntNum getNum() {
	IntNum a(0);
	return a;
}


// String ��
inline void test(const char *title, bool value) { 
	cout << title << " return " << (value ? "true" : "false") << endl; 
}
// �ַ������ӡ���C���
char *link(char* a, char*b) {
	int m = 0, n = 0;
	while (a[m] != '\0')
		m++;
	while (b[n] != '\0')
		n++;
	char *c = new char[n + m + 1];
	for (int i = 0; i < m; i++)
		c[i] = a[i];
	for (int i = m; i < m + n; i++)
		c[i] = b[i - m];
	c[n + m] = '\0';
	return c;
}


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
	for (int i=0; i < 3; i++) {
		for (int j=0; j < i; j++) {
			swap(a[i][j], a[j][i]);
		}
	}*/

	// ����ת�á�����̬�ڴ����
	/*int **a;
	a = new int*[3];
	for (int i = 0; i < 3; i++) {
		a[i] = new int[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	for (int i=0; i < 3; i++) {
		for (int j=0; j < i; j++) {
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
	/*int(*cp)[9][8] = new int[7][9][8];// cp ��һ��[9][8]�����ͷ
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 8; k++)
				*(*(*(cp + i) + j) + k) = (i * 100 + j * 10 + k);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 8; k++)
				cout << cp[i][j][k] << "    ";
			cout << endl;
		}
		cout << endl;
	}
	delete[] cp;*/


	// ��̬������
	/*int count;
	cout << "Please enter the count of points:";
	cin >> count;
	ArrayOfPoint points(count);
	points.element(0).move(5, 0);
	points.element(1).move(15, 20);*/

	// vector
	/*vector<int> v = { 1,2,3 };
	for (auto i = v.begin(); i != v.end(); i++)
		cout << *i << endl;
	for (auto e : v)
		cout << e << endl;*/
	
	// ��㸴�ƹ���
	/*ArrayOfPoint pointsArray1(3);
	pointsArray1.element(0).move(5, 10);
	pointsArray1.element(1).move(15, 20);

	ArrayOfPoint pointsArray2(pointsArray1);

	cout << "Copy of pointsArray1: " << endl;
	cout << "Point_0 of array2:" << pointsArray2.element(0).getx() << "," << pointsArray2.element(0).gety() << endl;
	cout << "Point_0 of array2:" << pointsArray2.element(1).getx() << "," << pointsArray2.element(1).gety() << endl;

	pointsArray1.element(0).move(35, 10);
	pointsArray1.element(1).move(25, 20);

	cout << "Copy of pointsArray1: " << endl;
	cout << "Point_0 of array2:" << pointsArray2.element(0).getx() << "," << pointsArray2.element(0).gety() << endl;
	cout << "Point_0 of array2:" << pointsArray2.element(1).getx() << "," << pointsArray2.element(1).gety() << endl;
*/

	// �ƶ�����
	/*cout << getNum().getInt() << endl;*/

	//String
	/*string s1 = "DEF";
	cout << "s1 is " << s1 << endl;
	string s2;
	cout << "Please enter s2 :";
	cin >> s2;
	cout << "length of s2: " << s2.length() << endl;

	test("s1<=\"ABC\"", s1 <= "ABC");
	test("\"DEF\"<=s1", "DEF" <= s1);

	s2 += s1;
	cout << "s2=s2+s1: " << s2 << endl;
	cout << "length of s2: " << s2.length() << endl;

	string city, state;
	getline(cin, city, ',');
	getline(cin, state);
	cout << "City:" << city << " State: " << state << endl;*/

	return 0;
}