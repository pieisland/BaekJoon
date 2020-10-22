#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int parent[100001];
vector<int> connect[100001];
int n;

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

	queue<int> q;
	q.push(1);
	
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < connect[current].size(); i++) {
			int next = connect[current][i];
            if (next == 1) continue;
			if (parent[next] == 0) {
				parent[next] = current;
				q.push(next);
			}
		}
	}

	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';

	return 0;
}
