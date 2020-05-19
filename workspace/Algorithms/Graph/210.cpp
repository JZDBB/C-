#include"graph.h"

// 210. �γ̱� II
// �洢����ͼ
vector<vector<int>> edges;
vector<int> visited;// ���ÿ���ڵ��״̬��0=δ������1=�����У�2=�����
vector<int> result;// ��������ģ��ջ���±� 0 Ϊջ�ף�n-1 Ϊջ��
bool invalid;// �ж�����ͼ���Ƿ��л�
void dfs(int i) {
	visited[i] = 1;
	for (int j : edges[i]) {
		if (visited[j] == 0) {
			dfs(j);
			if (invalid) return;
		}
		if (visited[j] == 1) {
			invalid = true;
			return;
		}
	}
	visited[i] = 2;
	result.push_back(i);
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	edges = vector<vector<int>>(numCourses);
	visited = vector<int>(numCourses, 0);
	invalid = false;
	for (auto p : prerequisites) edges[p[1]].push_back(p[0]);
	for (int i = 0; i < numCourses; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	if (invalid) return {};
	reverse(result.begin(), result.end());
	return result;
}