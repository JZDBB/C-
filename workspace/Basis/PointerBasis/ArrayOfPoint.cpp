#include "ArrayOfPoint.h"
#include<iostream>
#include <assert.h>
using namespace std;

ArrayOfPoint::ArrayOfPoint(int size) :size(size) { points = new Point[size]; }

ArrayOfPoint::ArrayOfPoint(const ArrayOfPoint& pointsArray) { // ���ƹ��죨��㸴�ƣ���ֹ��������
	size = pointsArray.size;
	points = new Point[size];
	for (int i = 0; i < size; i++) {
		points[i] = pointsArray.points[i];
	}
}

ArrayOfPoint::~ArrayOfPoint() { cout << "Deleting ..."; delete[] points; }

Point& ArrayOfPoint::element(int index) {
	assert(index >= 0 && index < size);// �ж��±겻��Խ��
	return points[index];// ����һ�����ò��ܶԸö�����в���������Ƿ���ֵ���޷���������������ֵ�ܹ����в���
}
