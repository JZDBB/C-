#pragma once
//����������ʵʩvisit����������ָ�룬ֻ����ֲ����޸ģ�
template <typename T>
void List<T>::traverse(void(*visit) (T&)) {
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);
}
//����������ʵʩvisit�������������󣬿�ȫ�����޸ģ�
template <typename VST>
void traverse(VST & visit) {
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);
}