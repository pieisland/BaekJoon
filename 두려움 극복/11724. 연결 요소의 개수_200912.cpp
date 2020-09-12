#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

//배열로 할 수도 있고 vector로 연결된 애들만 따로 넣을 수도 있다.
int node[1001][1001];
int visited[1001];
int n, m;
int answer;

void bfs(int point) {
	queue<int> q;
	q.push(point);
	visited[point] = 1;

	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (node[now][i] == 1 && visited[i] == 0) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node[a][b] = 1;
		node[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			bfs(i);
			answer++;
		}
	}

	printf("%d\n", answer);

	return 0;
}
