#pragma once
#ifndef CELL_H_
#define CELL_H_
#include <queue>
#include<iostream>
using namespace std;

class Cell;
extern priority_queue<Cell> cellQueue;

class Cell {
private:
	static int count;	//����
	int id;		//���
	int time;	//����ʱ��
public:
	Cell(int birth);
	int getId() const;	
	int getSplitTime() const;	
	bool operator < (const Cell& s) const;	
	void split() const;
	~Cell();
};

#endif // !CELL_H_