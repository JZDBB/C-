#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<string>
#include<list>
using namespace std;

//#include"LinkedList.h"
//#include"Array.h"
#include"Cell.h"


// ����ģ��
//template <typename T>
//class array
//{
//public:
//	template <typename T>//��Ϊ��Ԫ���������⺯�������Ե����ⶨ��һ������ģ��
//	friend ostream &operator << (ostream &, T<T1> &);//�������
//private:
//	T array;
//};
//template<typename T1>
//ostream &operator<<(ostream &OUT1, T<T1> &M)
//{
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			OUT1 << M.array[i][j];
//			cout << ' ';
//		}
//		cout << endl;
//	}
//	return OUT1;
//}
//template<class T>
//void outputArray(const T *array, int count) {
//	for (int i = 0; i < count; i++)
//		cout << array[i] << " ";
//	cout << endl;
//}

// ����STL
double square(double x) {
	return x * x;
}

//���������������p��n��T���͵���ֵ���򣬽����ͨ�����������result���
template <class T, class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result) {
	//ͨ�����������p���������ݴ�����������s��
	vector<T> s;
	for (; first != last; ++first)
		s.push_back(*first);
	//��s��������sort�����Ĳ���������������ʵ�����
	sort(s.begin(), s.end());
	//��s����ͨ��������������
	copy(s.begin(), s.end(), result);
}


// ģ��ϸ������ queue

class Cell;




int main() {
	// ����ģ�塪��debug
	/*const int A = 8, B = 8, C = 20;
	int a[A] = {1, 2, 3,4 ,5 ,6 ,7, 8};
	double b[B] = { 1.2, 3.3, 5.6,1.2, 3.3, 5.6, 4.5,6.7 };
	char c[C] = "Welcome!";
	outputArray(a, A);
	outputArray(b, B);
	outputArray(c, C);*/

	// ���� ����debug
	/*LinkedList<int> list;
	for (int i = 0; i < 10; i++)
	{
		int item;
		cin >> item;
		list.insertFront(item);
	}
	cout << "List:";
	list.reset();
	while (!list.endOfList)
	{
		cout << list.data() << " ";
		list.next();
	}*/

	// STL����
	//�ӱ�׼����������ɸ�ʵ�����ֱ����ǵ�ƽ�����
	/*transform(istream_iterator<double>(cin), istream_iterator<double>(),
		ostream_iterator<double>(cout, "\t"), square);
	cout << endl;*/

	//��s�����������������
	//double a[5] = { 1.2, 2.4, 0.8, 3.3, 3.2 };
	//mySort<double>(a, a + 5, ostream_iterator<double>(cout, " "));
	//cout << endl;
	////�ӱ�׼����������ɸ��������������Ľ�����
	//mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
	//cout << endl;


	// ˳����������vector/deque

	//istream_iterator<int> i1(cin), i2;	//����һ�Զ�������������
	//vector<int> s1(i1, i2);	//ͨ���������������ӱ�׼����������������
	//sort(s1.begin(), s1.end());			//���������������
	//deque<int> s2;
	////����ѭ������s1
	//for (vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter) {
	//	if (*iter % 2 == 0)	//ż���ŵ�s2β��
	//		s2.push_back(*iter);
	//	else				//�����ŵ�s2�ײ�
	//		s2.push_front(*iter);
	//}
	////��s2�Ľ�����
	//copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;


	// ˳��������������ƴ��

	//string names1[] = { "Alice", "Helen", "Lucy", "Susan" };
	//string names2[] = { "Bob", "David", "Levin", "Mike" };
	//list<string> s1(names1, names1 + 4); //��names1��������ݹ����б�s1
	//list<string> s2(names2, names2 + 4); //��names2��������ݹ����б�s2
	////��s1�ĵ�һ��Ԫ�طŵ�s2�����
	//s2.splice(s2.end(), s1, s1.begin());
	//list<string>::iterator iter1 = s1.begin(); //iter1ָ��s1��
	//advance(iter1, 2); //iter1ǰ��2��Ԫ�أ�����ָ��s1��3��Ԫ��
	//list<string>::iterator iter2 = s2.begin();  //iter2ָ��s2��
	//++iter2; //iter2ǰ��1��Ԫ�أ�����ָ��s2��2��Ԫ��
	//list<string>::iterator iter3 = iter2; //��iter2��ʼ��iter3
	//advance(iter3, 2); //iter3ǰ��2��Ԫ�أ�����ָ��s2��4��Ԫ��
	////��[iter2, iter3)��Χ�ڵĽ��ӵ�s1��iter1ָ��Ľ��ǰ
	//s1.splice(iter1, s2, iter2, iter3);
	////�ֱ�s1��s2���
	//copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " "));
	//cout << endl;
	//copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
	//cout << endl;


	// ģ��ϸ������
	srand(static_cast<unsigned>(time(0)));
	int t;	//ģ��ʱ�䳤��
	cout << "Simulation time: ";
	cin >> t;
	cellQueue.push(Cell(0));	//����һ��ϸ��ѹ�����ȼ�����
	while (cellQueue.top().getSplitTime() <= t) {
		cellQueue.top().split();	//ģ����һ��ϸ���ķ���
		cellQueue.pop();			//���ոշ��ѵ�ϸ������
	}







	return 0;
}