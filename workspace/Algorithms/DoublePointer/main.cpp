#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


// 633. Sum of Square Numbers (Easy)
bool judgeSquareSum(int c) {
	// ���� ʱ�临�Ӷ� O(sqrt(n)) ��ʵ�ϻ��һЩ
	for (int i = 1; pow(i, 2) <= c/2; i++) {
		double diff = c - pow(i, 2);
		if (sqrt(diff) - int(sqrt(diff)) == 0) return true;
	}
	return false;

	// ˫ָ�� ʱ�临�Ӷ� O(sart(n))
	int left = 0;
	int right = (int)sqrt(c);
	while (left < right) { // ������
		long sum = pow(left, 2) + pow(right, 2); // �����ͷ���� ���� 64λ����ϵͳ��intռ���ֽڣ�longռ8�ֽڣ�long���ݷ�Χ��Ϊ��-2^63~2^63-1
		if (sum < c) left++;
		else if (sum > c)right--;
		else return true;
	}
	return false;

}

//167. ����֮�� II - ������������
vector<int> twoSum(vector<int>& numbers, int target) {
	// ˫ָ�롪�����������ռ�
	int index1 = 1, index2 = numbers.size();
	while (index1 < index2) {
		int sum = numbers[index1 - 1] + numbers[index2 - 1];
		if (sum == target) return vector<int>{index1, index2};
		else if (sum > target) index2--;
		else index1++;
	}
	return {};
}


char a[10] = { 'a', 'e', 'i', 'o', 'u' , 'A', 'E', 'I', 'O', 'U' };
vector<char> Vowels(a, a + 10);

// 345. ��ת�ַ����е�Ԫ����ĸ
string reverseVowels(string s) {
	// me (42ms)
	int left = 0;
	int right = s.size()-1;
	while (left < right) {
		if (find(Vowels.begin(), Vowels.end(), s[left]) != Vowels.end()) {
			if (find(Vowels.begin(), Vowels.end(), s[right]) != Vowels.end()) {
				swap(s[left], s[right]);
				left++;
				right--;
			}
			else right--;
		}
		else left++;
	}

	// �Ľ��� 
	// 1.����Ƕ��ѭ��������һ��ʱ�� (32ms)
	// 2.��������find������Ϊ���жϣ���ż�����һ��ʱ�䡣(16ms)
	// 3.���ж��еģ�=��&&�ֱ��Ϊ==��||�ּ�����һ��ʱ�䡣(8ms)
	int left = 0;
	int right = s.size() - 1;
	bool flag1 = 0, flag2 = 0;
	while (left < right) {
		if (s[left] == 'a' || s[left] == 'o' || s[left] == 'e' || s[left] == 'i' || s[left] == 'u' || s[left] == 'A' || s[left] == 'E' || s[left] == 'I' || s[left] == 'O' || s[left] == 'U') {
			flag1 = 1;
		}
		else left++;
		if (s[right] == 'a' || s[right] == 'o' || s[right] == 'e' || s[right] == 'i' || s[right] == 'u' || s[right] == 'A' || s[right] == 'E' || s[right] == 'I' || s[right] == 'O' || s[right] == 'U') {
			flag2 = 1;
		}
		else right--;
		if (flag1&&flag2) {
			swap(s[left], s[right]);
			left++;
			right--;
			flag1 = flag2 = 0;
		}
	}

	return s;
}

int main() {
	

	return 0;
}