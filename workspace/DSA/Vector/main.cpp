#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#include"search.h"
#include"sort.h"


int main() {

	// ����
	vector<int> arr;
	int index;
	int a[20] = { 1, 4, 3, 4, 5, 12, 7, 15, 11, 14 };
	arr.insert(arr.begin(), a, a + 9);

	// ð������
	bubbleSort1(arr);
	
	// ���ֲ���
	index = Bisearch(arr, 6, 0, 9);



	return 0;
}
