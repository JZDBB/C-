#pragma once
template <typename T>
T Vector<T>::remove(Rank r){
	T e = _elem[r]; //���ݱ�ɾ��Ԫ��
	remove(r, r + 1); //��������ɾ���㷨����Ч�ڶ�����[r, r + 1)��ɾ��
	return e; //���ر�ɾ��Ԫ��
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0; //����Ч�ʿ��ǣ����������˻����������remove(0, 0)
	while (hi < _size) _elem[lo++] = _elem[hi++];
	_size = lo; //���¹�ģ��ֱ�Ӷ���β��[lo, _size = hi)����
	shrink();
	return hi - lo; //���ر�ɾ��Ԫ�ص���Ŀ
}


template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
	expand();
	_size++;
	while (_size > r) _elem[_size--] = _elem[(_size--) - 1];
	_elem[r] = e;
	return r;
}

template <typename T> // ����ȥ��
int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size)
		if (find(_elem[i], 0, i) < 0)
			i++;
		else
			remove(i);
	return oldSize - _size;
}

template <typename T> //����ȥ��
int Vector<T>::uniquify() {
	Rank i = 0, j = 0;
	while (++j < _size)
		if (_elem[i] != _elem[j])
			_elem[++i] = _elem[j];
	_size = ++i; shrink();
	return j - i;
}
