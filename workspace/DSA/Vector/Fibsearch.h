#pragma once
#include"Fib.h"
template <typename T>
static Rank fibSearch(T* S, T const& e, Rank lo, Rank hi) {
	printf("FIB search (B)\n");
	for (Fib fib(hi - lo); lo < hi; ) { //Fib�����Ʊ���
		while (hi - lo < fib.get()) fib.prev(); //�Ժ���ǰ˳����ң���̯O(1)��
		Rank mi = lo + fib.get() - 1; //ȷ������Fib(k) - 1�����
		(e < S[mi]) ? hi = mi : lo = mi + 1; //�ȽϺ�ȷ������ǰ���[lo, mi)�����(mi, hi)
	}
	return --lo;
}