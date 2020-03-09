#pragma once
#include"Fibsearch.h"
#include"Binsearch.h"

template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
	/*while (lo <= hi) {
		if (_elem[hi--] == e) break;
	}*/
	while ((lo < hi--) && (e != _elem[hi])); //�Ӻ���ǰ��˳�����
	return hi;
}

template <typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const {
	return (rand() % 2) ? //����50%�ĸ������ʹ�ö��ֲ��һ�Fibonacci����
		binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}