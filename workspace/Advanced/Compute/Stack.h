#pragma once
template <class T, int SIZE=50>
class Stack
{
public:
	Stack();
	~Stack();
	bool stackEmpty();//�п�
	bool stackFull();//����
	void clearStack();//���
	int stackLength();//����
	void push(const T &item);//ѹջ
	T pop();//��ջ
	const T &peek() const;//��ȡջ��
	void stackTranverse();//����ջ

private:
	T list[SIZE];//ջָ��
	int Size;//ջ����
	int Top;//ջ��
};