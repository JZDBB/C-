#include "Solutions.h"



Solutions::Solutions()
{
}


Solutions::~Solutions()
{
}

vector<int> Solutions::twoSum(vector<int>& nums, int target)
{
	// ����
	/*for (int i = 0; i < nums.size(); i++) {
		int sub = target - nums[i];
		for (int j = i+1; j < nums.size(); j++) {
			if ((j != i) && (nums[j] == sub)) return { i, j };
		}
	}*/

	// ��ϣ
	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); i++)
	{
		if (m.find(target - nums[i]) != m.end())       //m�д��ڶ�Ӧ�ļ�ֵ
			return { m[target - nums[i]] , i };         //��ΪiΪ�ϴ��Ԫ�أ���ʱ��ӽ�ȥ�ļ�ֵ����С��i������i�ں���

		m[nums[i]] = i;       //��map�����Ԫ��
	}

	return {};
}


vector<vector<int>> Solutions::threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size() <= 2) return res;

	sort(nums.begin(), nums.end());

	
	return res;
}