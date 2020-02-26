#include<iostream>
using namespace std;
#include"Complex.h"
#include"Clock.h"

// ���������
class Base1 {
public:
	Base1(int i) { cout << "Constructing Base1  " << i << endl; }
	~Base1() { cout << "Destructing Base1  " << endl; }
};
class Base2 {
public:
	Base2(int j) { cout << "Constructing Base2  " << j << endl; }
	~Base2() { cout << "Destructing Base2  " << endl; }
};

class Base3 {
public:
	Base3() { cout << "Constructing Base3" << endl; }
	~Base3() { cout << "Destructing Base3  " << endl; }
};

class Derived :public Base2, public Base1, public Base3 {
public:
	Derived(int a, int b, int c, int d) :Base1(a), member2(b), member1(c), Base2(d) {};
	//�̳к����
	~Derived() { cout << "Destructing ALL  " << endl; }
private:
	Base1 member1;
	Base2 member2;
	Base3 member3;
};


// ��Ա����
class Base11 {
public:
	int var;
	void fun() { cout << "Member of Base1  " << endl; }
};
class Base12 {
public:
	int var;
	void fun() { cout << "Member of Base2  " << endl; }
};
class Derived2 :public Base11, public Base12{
public:
	int var;
	void fun() { cout << "Member of  Derived2 " << endl; }
};

// ��̳ж����Ժ����ࡪ���������
class Base0 {
public:
	Base0(int var) :var0(var) {};
	int var0;
	void fun0() { cout << "Member of Base0  " << endl; }
};
class Base01: virtual public Base0 { // virtual �����
public:
	Base01(int var) :Base0(var) {};
	int var1;
};
class Base02 : virtual public Base0 {
public:
	Base02(int var) :Base0(var) {};
	int var2;
};
class Derived3 :public Base01, public Base02 {
public:
	Derived3(int var) :Base0(var), Base01(var), Base02(var){}; // ���˸�ֱ�ӻ��ഫ�λ�Ҫ����Զ���ഫ�Σ�
	int var;
	void fun() { cout << "Member of  Derived3 " << endl; }
};


// �������������
Complex operator + (const Complex &c1, const Complex &c2) {
	return Complex(c1.real + c2.real, c1.imag + c2.imag); // ��Ҫ����˽�г�Աreal��imag����Ϊ��Ԫ
}
Complex operator - (const Complex &c1, const Complex &c2) {
	return Complex(c1.real - c2.real, c1.imag - c2.imag); 
}

ostream & operator << (ostream &out, const Complex &c) {
	out << "(" << c.real << "," << c.imag << ")" << endl;
	return out;
}

// �麯��ʵ�����ж�̬
class Base21 {
public:
	Base21() {};
	~Base21() {};
	virtual void display() const { cout << "display Base1" << endl; }
};
class Base22 :public Base21{
public:
	Base22() {};
	~Base22() {};
	virtual void display() const { cout << "display Base2" << endl; }
};

class Derived4 :public Base22{
public:
	Derived4() {};
	~Derived4() {};
	virtual void display() const { cout << "display Derived" << endl; }
};

void fun(Base21 *ptr) {
	ptr->display();
}



int main() {
	// ���������
	//Derived D(7, 6, 5, 4);

	// ��Ա����
	/*Derived2 d;
	Derived2 *p = &d;
	d.var = 1;
	d.fun();
	d.Base11::var = 2;// ����/����������
	d.Base11::fun();
	p->Base12::var = 3;// ָ�����
	p->Base12::fun();*/


	// ��̳ж����Ժ����ࡪ��Ӧ�ñ��⣬��Ϊ�����var0û�����壬�����������
	/*Derived3 d(1);
	//d.Base01::var0 = 2;
	//d.Base01::fun0();
	//d.Base02::var0 = 3;
	//d.Base02::fun0();
	d.var0 = 2;
	d.fun0(); */

	// ����˫Ŀ���������
	/*Complex c1(5, 4), c2(1, 3), c3, c4;
	c3 = c1 + c2;
	c4 = c1 - c2;*/

	// ���ڵ�Ŀ��������� ���� ��������ǰ�üӺͺ��õ�����
	/*Clock myClock(23, 59, 59);
	cout << "First:";
	myClock.showTime();
	cout << "Second:";
	(myClock++).showTime();
	cout << "Third:";
	(myClock).showTime();
	cout << "Fourth:";
	(++myClock).showTime();*/


	// ����˫Ŀ���������
	/*Complex c1(5, 4), c2(1, 3), c3, c4;
	c3 = c1 + c2;
	c4 = c1 - c2;
	cout << "c4:" << c4 << endl;*/

	// �麯�����ж�̬ ���� ������ʱ�������õĶ�Ӧ��ָ�����
	Base21 base1;
	Base22 base2;
	Derived4 d;
	fun(&base1);
	fun(&base2);
	fun(&d);




	return 0;
}