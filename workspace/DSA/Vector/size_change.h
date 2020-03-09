#pragma once

template <typename T>
void Vector<T>::expand() {
	if (_size < _capacity) return; //��δ��Աʱ����������
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY; //��������С����
	T* old_elem = &_elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; i++){
		_elem[i] = old_elem[i];
	}
	delete [] old_elem; // �ͷſռ䣡��
}

template <typename T>
void Vector<T>::shrink() {
	if (_capacity < DEFAULT_CAPACITY << 1) return; //����������DEFAULT_CAPACITY����
	if (_size << 2 > _capacity) return; //��25%Ϊ��
	T* old_elem = &_elem;
	_elem = new T[_capacity >>= 1];
	for (int i = 0; i < _capacity; i++) {
		_elem[i] = old_elem[i];
	}
	delete[] old_elem;
}
