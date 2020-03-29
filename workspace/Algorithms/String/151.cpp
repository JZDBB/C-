#include"string_func.h"

// 151. ��ת�ַ�����ĵ��� ����**
string reverseWords(string s) {
	// ��θ�ֵ�ܺ�ʱ
	/*string res;
	int i = 0;
	while (i<s.size()) {
		string word;
		int len = 0;
		while (s[i] != ' '&& i<s.size()) {
			word.insert(word.end(), s[i++]);
			len++;
		}
		if (!word.empty()) {
			res.insert(res.begin(), ' ');
			for (int k = len - 1; k >= 0; k--) {
				res.insert(res.begin(), word[k]);
			}
		}
		i++;
	}
	res.pop_back();
	return res;*/

	if (s.empty()) return "";
	//�ȷ�ת
	reverse(s.begin(), s.end());
	//ȥ��ǰ��ո�
	int start = 0, end = s.size() - 1;
	while (s[start] == ' ' && start < s.size()) start++;
	while (s[end] == ' ' && end > 0) end--;
	if (start > end) return "";

	//�Ե��ʽ��з�ת(����ָ��-����ָ�룬ȷ����Ҫ��ת�ĵ���)
	for (int right = start, left = start; right <= end;)
	{
		while (s[right] != ' ' && right <= end) right++;
		reverse(s.begin() + left, s.begin() + right);
		left = right;
		while (s[left] == ' ' && left <= end) left++;
		right = left;
	}

	//ȥ�����ʼ�Ķ���ո�
	int new_index = start;
	for (int i = start; i <= end; i++)
	{
		if (s[i] == ' ' && s[i - 1] == ' ') continue;
		s[new_index] = s[i];
		new_index++;
	}
	return s.substr(start, new_index - start);
}