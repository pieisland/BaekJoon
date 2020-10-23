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
int leaf;

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

	//여기서 leaf를 표시해주는 부부만 추가
	if (check == 0) {
		//마지막임
		if (answer < value) { 
			answer = value; 
			leaf = start;
		}
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

	//모든 정점에서 시작해서 가장 먼 거리를 찾는 과정 때문에 시간초과가 난 듯 함.
	//그래서 leaf를 찾고 leaf에서 다시 찾는 두 번만 거치게 해본다.

	visited[1] = 1;
	dfs(1, 0);
	visited[1] = 0;

	visited[leaf] = 1;
	dfs(leaf, 0);
	visited[leaf] = 0;

	cout << answer << '\n';

	return 0;
}
