#pragma once

const int SPLIT_TIME_MIN = 500;		//ϸ���������ʱ��
const int SPLIT_TIME_MAX = 2000;	//ϸ�������ʱ��

class Cell;
priority_queue<Cell> cellQueue;

class Cell {	//ϸ����
private:
	static int count;	//ϸ������
	int id;		//��ǰϸ�����
	int time;	//ϸ������ʱ��
public:
	Cell(int birth);
	int getId() const;	//�õ�ϸ�����
	int getSplitTime() const;	//�õ�ϸ������ʱ��
	bool operator < (const Cell& s) const;	//���塰<��

	//ϸ������
	void split() const;
	~Cell();
};
int Cell::count = 0;

