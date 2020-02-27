#pragma once
#ifndef ARRAY_H_
#define ARRAY_H_


template <class T>
class Array
{
public:
	Array(int s=50);
	Array(const Array<T> &a);
	~Array();
	
	// ����
	Array<T> & operator = (const Array<T> &rhs);
	T & operator [] (int i); // �����±������
	const T & operator [] (int i) const;
	operator T * (); // ����ָ������
	operator const T * () const; // ����ָ��
	int getSize() const;
	void resize(int s);

private:
	T* list; // ��Ŷ�̬���������ڴ���׵�ַ
	int size;
};

#endif // !ARRAY_H_