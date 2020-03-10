#pragma once
template <typename T>
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const {
	while (n--) {
		if (p->data == e) return p;
		p = p->pred;
	}
	return nullptr;
}

template <typename T>
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) const {
	do {
		p = p->pred;
		n--;
	} while ((n > -1) && (e > p->data));
	return p;
}

template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n) {
	ListNodePosi(T) max = p;
	for (ListNodePosi(T) cur = p; 1 < n; n--) //���׽ڵ�p�������������ڵ���һ��max�Ƚ�
		if (!lt((cur = cur->succ)->data, max->data)) //����ǰԪ�ز�С��max
			max = cur;
	return max;
}