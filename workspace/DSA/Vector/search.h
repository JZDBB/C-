#pragma once
#include"vector.h"

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

template <typename T>
static Rank binSearch(T* S, T const& e, Rank lo, Rank hi) {
	Rank mi;
	while (lo < hi) {
		mi = lo / 2 + hi / 2;
		e < S[mi] ? hi = mi : lo = mi + 1;
	}
	return lo - 1;
}

#include"Fib.h"
template <typename T>
static Rank fibSearch(T* S, T const& e, Rank lo, Rank hi) {
	template <typename T> static Rank fibSearch(T* S, T const& e, Rank lo, Rank hi) {
		printf("FIB search (B)\n");
		for (Fib fib(hi - lo); lo < hi; ) { //Fib�����Ʊ���
			while (hi - lo < fib.get()) fib.prev(); //�Ժ���ǰ˳����ң���̯O(1)��
			Rank mi = lo + fib.get() - 1; //ȷ������Fib(k) - 1�����
			(e < S[mi]) ? hi = mi : lo = mi + 1; //�ȽϺ�ȷ������ǰ���[lo, mi)�����(mi, hi)
		} 
		return --lo;
	}
}