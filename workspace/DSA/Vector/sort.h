#pragma once
#include<vector>
using namespace std;

template <typename T>
void bubbleSort(vector<T> &V) { // ������
	int lo = 0, hi = V.size();
	T temp;
	while (lo < --hi) {
		for (int i = lo; i < hi; i++) {
			if (V[i] > V[i + 1]) {
				temp = V[i];
				V[i] = V[i + 1];
				V[i + 1] = temp;
			}	
		}
	}
}

template <typename T>
void bubbleSort1(vector<T> &V) { // ��Ծ��
	int lo = 0, hi = V.size();
	for (int last = --hi; lo < hi; hi = last)
		for (int i = last = lo; i < hi; i++)
			if (V[i] > V[i + 1]) //��������
				swap(V[last = i], V[i + 1]); //������ʹ�ֲ�����
}
