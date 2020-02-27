#include "Node.h"


template <class T>
Node<T>::Node(const T &item, Node<T>* next)
{
}

template <class T>
Node<T>::~Node()
{
}

template <class T>
void Node<T>::insertAfter(Node<T> *p) {
	p->next = next; // ����ʵ��̽��
	next = p;
}
template<class T>
Node<T>* Node<T>::deleteAafter()
{
	Node<T> *temp = next;
	if (next == 0)
		return 0;
	next = temp->next;
	return temp; // ָ��ɾ���Ľ�㣬��ֹ�����в���
}

template<class T>
Node<T>* Node<T>::nextNode()
{
	return next;
}

template<class T>
Node<T>* Node<T>::nextNode() const
{
	return next;
}
