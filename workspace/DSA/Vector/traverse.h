#pragma once
 //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
template <typename T> void Vector<T>::traverse(void(*visit) (T&)) //��������ָ�����
{
	for (int i = 0; i < _size; i++) visit(_elem[i]);
} //��������

template <typename VST> 
void Vector<T>::traverse(VST&); //������ʹ�ú������󣬿�ȫ�����޸ģ�