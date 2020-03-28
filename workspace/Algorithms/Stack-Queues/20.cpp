#include"Stack.h"

// 20. ��Ч������ ���� ��Ҫע��һЩ�����������ע�ͣ�
bool isValid(string s) {
	if (s.size() % 2 != 0) return false; // ���ٺܶ��������~
	stack<char> arm;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') arm.push(s[i]);
		else {
			if (arm.empty()) return false; // �� "}{"
			switch (s[i]) {
			case ')': if (arm.top() != '(') return false; break; // break����Ҫ����
			case '}': if (arm.top() != '{') return false; break;
			case ']': if (arm.top() != '[') return false; break;
			}
			arm.pop();
		}
	}
	if (!arm.empty()) return false; // ��"(("
	return true;
}