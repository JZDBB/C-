
#pragma once

template <typename T> int Vector<T>::uniquify() { //���������ظ�Ԫ���޳��㷨����Ч�棩
   int oldSize = _size; int i = 1; //��ǰ�ȶ�Ԫ�ص��ȣ���ʼ����Ԫ��
   while ( i < _size ) //��ǰ�����һ�ȶԸ�������Ԫ��
      _elem[i - 1] == _elem[i] ? remove ( i ) : i++; //����ͬ����ɾ�����ߣ�����ת����һԪ��
   return oldSize - _size; //������ģ�仯��������ɾ��Ԫ������
}