#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n, m;
int paper[500][500];
int check[500][500];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool isinside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	else return false;
}

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	check[y][x] = 1;
	int count = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (isinside(ny, nx) && check[ny][nx] == 0 && paper[ny][nx] == 1) {
				q.push({ ny, nx });
				check[ny][nx] = 1;
				count += 1;
			}
		}
	}

	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	int count = 0;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j] == 1 && check[i][j]==0) {
				int ret;
				ret = bfs(i, j);
				count += 1;
				if (ret > answer) answer = ret;
			}
		}
	}

	cout << count << '\n' << answer << '\n';

	return 0;
}
