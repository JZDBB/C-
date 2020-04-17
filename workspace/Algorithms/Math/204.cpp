#include"Math.h"

// 204. ��������
bool isPrimes(int n) {
	for (int i = 2; i*i < n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}
// ��������ɸ��
int countPrimes(int n) {
	vector<bool> Primes(n, true);
	int count = 0;
	for (int i = 2; i < n; i++) {
		if (Primes[i]) {
			count++;
			for (int j = i+i; j < n; j+=i) {
				Primes[j] = false;
			}
		}
		
	}
	return count;
}