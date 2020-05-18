#include"graph.h"

// 210. �γ̱� II
// �洢����ͼ
vector<vector<int>> edges;
vector<int> visited;// ���ÿ���ڵ��״̬��0=δ������1=�����У�2=�����
vector<int> result;// ��������ģ��ջ���±� 0 Ϊջ�ף�n-1 Ϊջ��
bool invalid;// �ж�����ͼ���Ƿ��л�
void dfs(int u) {
	visited[u] = 1;
	for (int v : edges[u]) {
		// �����δ��������ô�������ڽڵ�
		if (visited[v] == 0) {
			dfs(v);
			if (invalid) {
				return;
			}
		}
		// ����������С�˵���ҵ��˻�
		else if (visited[v] == 1) {
			invalid = true;
			return;
		}
	}
	// ���ڵ���Ϊ������ɡ�
	visited[u] = 2;
	// ���ڵ���ջ
	result.push_back(u);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	edges.resize(numCourses);
	visited.resize(numCourses);
	for (const auto& info : prerequisites) {
		edges[info[1]].push_back(info[0]);
	}
	// ÿ����ѡһ����δ�������Ľڵ㣬��ʼ���������������
	for (int i = 0; i < numCourses && !invalid; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	if (invalid) {
		return {};
	}
	// ���û�л�����ô������������
	// ע���±� 0 Ϊջ�ף������Ҫ�����鷴�����
	reverse(result.begin(), result.end());
	return result;
}