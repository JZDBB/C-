#pragma once
//������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
template <typename T> 
void Vector<T>::traverse(void(*visit) (T&)) //��������ָ�����
{
	for (int i = 0; i < _size; i++) visit(_elem[i]);
} //��������

//������ʹ�ú������󣬿�ȫ�����޸ģ�
//template <typename VST> 
//void Vector<T>::traverse(VST& visit)
//{ for (int i = 0; i < _size; i++) visit(_elem[i]); }