#include "Cell.h"
#include<iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;



Cell::Cell(int birth):id(count++) {	//birthΪϸ������ʱ��
	//��ʼ����ȷ��ϸ������ʱ��
	time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN)) + SPLIT_TIME_MIN;
}

int Cell::getId() const
{
	return id;
}

int Cell::getSplitTime() const
{
	return time;
}

bool Cell::operator<(const Cell & s) const
{
	return time > s.time;
}

void Cell::split() const
{
	Cell child1(time), child2(time);	//����������ϸ��
	cout << time << "s: Cell #" << id << " splits to #"
		<< child1.getId() << " and #" << child2.getId() << endl;
	cellQueue.push(child1);	//����һ����ϸ��ѹ�����ȼ�����
	cellQueue.push(child2);	//���ڶ�����ϸ��ѹ�����ȼ�����
}

Cell::~Cell()
{
}

