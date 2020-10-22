#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//\n 안 쓴 것 때문에 시간초과가 났다는 게.. 어이없었던 점.

int parent[100001];
vector<int> connect[100001];
int n;

void dfs(int node) {
	for (int i = 0; i < connect[node].size(); i++) {
		int nextNode = connect[node][i];
		if (parent[nextNode] == 0) {
			parent[nextNode] = node;
			dfs(nextNode);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		connect[v1].push_back(v2);
		connect[v2].push_back(v1);
	}

	parent[1] = 1;
	dfs(1);

	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';

	return 0;
}
