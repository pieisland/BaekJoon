#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v;
vector<pair<int, int>> tree[100001];
int answer = 0;
int visited[100001];

void clearVisited() {
	for (int i = 0; i <= 100000; i++) visited[i] = 0;
}

void dfs(int start, int value) {
	int check = 0;
	for (int i = 0; i < tree[start].size(); i++) {
		int node = tree[start][i].first;
		if (visited[node] == 1) continue;
		check = 1;
		visited[node] = 1;
		dfs(node, value + tree[start][i].second);
		visited[node] = 0;
	}

	if (check == 0) {
		//마지막임
		if (answer < value) answer = value;
		return;
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v;
	for (int i = 0; i < v; i++) {
		
		int vertex;
		cin >> vertex;
		while (1) {
			
			int a, b;
			cin >> a;
			if (a == -1) break;
			cin >> b;
			tree[vertex].push_back({ a, b });
		}
	}

	//모든 정점에서 시작해서 가장 먼 거리를 찾는 과정.
	//이것 때문에 시간초과가 난 듯 함.
	for (int i = 1; i <= v; i++) {
		clearVisited();
		visited[i] = 1;
		dfs(i, 0);
		visited[i] = 0;
	}

	cout << answer << '\n';

	return 0;
}
