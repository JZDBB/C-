#include "ArrayOfPoint.h"
#include<iostream>
#include <assert.h>
using namespace std;

ArrayOfPoint::ArrayOfPoint(int size) :size(size) { points = new Point[size]; }
ArrayOfPoint::~ArrayOfPoint() { cout << "Deleting ..."; delete[] points; }
Point& ArrayOfPoint::element(int index) {
	assert(index >= 0 && index < size);// �ж��±겻��Խ��
	return points[index];// ����һ�����ò��ܶԸö�����в���������Ƿ���ֵ���޷���������������ֵ�ܹ����в���
}
