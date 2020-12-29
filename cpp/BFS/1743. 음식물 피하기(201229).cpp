#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
너무 전형적인 문제인데.
실수로 인해서 시간 날린 게 억울함.
*/

int n, m, k;
int road[101][101];
int check[101][101];
int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

bool isinside(int y, int x) {
	if (y >= 1 && y <= n && x >= 1 && x <= m) return true;
	else return false;
}

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	check[y][x] = 1;

	int size = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (isinside(ny, nx) && check[ny][nx] == 0 && road[ny][nx]==1) {
				check[ny][nx] = 1;
				q.push({ ny, nx });
				size++;
			}
		}
	}

	return size;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		road[y][x] = 1;
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (road[i][j] && check[i][j] == 0) {
				int val = bfs(i, j);
				if (val > answer) answer = val;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}
