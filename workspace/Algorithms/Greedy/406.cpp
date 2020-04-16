#include"Greedy.h"

// 406. ��������ؽ�����
// ���Ӹߵ��˿�����ǰ�氫���ˣ��Ȳ�����Ӹߵġ�
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	if (people.size() < 2) return people;
	vector<vector<int>> res;
	sort(begin(people), end(people), [](const vector<int> &o1, const vector<int> &o2) {
		return (o1[0] > o2[0]) || (o1[0] == o2[0] && o1[1] < o2[1]);
	});
	int height = people[0][0];
	res.push_back(people[0]);
	for (int i = 1; i < people.size(); i++) {
		int k = people[i][1];
		res.insert(res.begin() + k, people[i]);
	}
	return res;
}