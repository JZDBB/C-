#pragma once
#include"Node.h"
template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T> &L);
	~LinkedList();

	LinkedList<T> & operator = (const LinkedList<T> &L);
	int getSize() const;
	bool isEmpty() const;
	void reset(int pos = 0);
	void next();
	bool endOfList() const;
	int currentPosition() const;
	void insertFront(const T &item);
	void insertRear(const T &item);
	void insertBefore(const T &item);
	void insertAfter(const T &item);
	T deleteFront();
	void deleteCurr();
	T& data(); // ���ص�ǰ����Ա���ݵ�����
	const T& data() const;// ���ص�ǰ����Ա���ݵĳ�����
	void clear();


private:
	Node<T> *front, *rear; // ��ͷ��β
	Node<T> *prevP, *currP; // ��ǰλ��ָ��
	int size, position;
	Node<T> *newNode(const T &item, Node<T> *ptrNext = NULL);
	void freeNode(Node<T> *p);
	void copy(const LinkedList<T> &L); // ��L���Ƶ���ǰ�б������ƹ��캯���͡�=������������


};

