#pragma once

class Fib { //Fibonacci������
private:
   int f, g; //f = fib(k - 1), g = fib(k)����Ϊint�ͣ��ܿ�ͻ���ֵ���
public:
   Fib ( int n ) //��ʼ��Ϊ��С��n����СFibonacci��
   { f = 1; g = 0; while ( g < n ) next(); } //fib(-1), fib(0)��O(log_phi(n))ʱ��
   int get()  { return g; } //��ȡ��ǰFibonacci�O(1)ʱ��
   int next() { g += f; f = g - f; return g; } //ת����һFibonacci�O(1)ʱ��
   int prev() { f = g - f; g -= f; return g; } //ת����һFibonacci�O(1)ʱ��
};

// FIB ����÷���
//Fib f(0);
//for (int i = 0; i < n; i++, f.next())
//	printf("fib(%2d) = %d\n", i, f.get());
//for (int i = 0; i <= n; i++, f.prev())
//printf("fib(%2d) = %d\n", n - i, f.get());