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
하나하나 나눠서 하는 게 아니라 더 좋은 방식으로 풀 수 있을 것 같은데..
*/

int n;
int house[16][16];
int dp[16][16]; //y, x 위치에 오는 경우의 수.
int direction1[2][2] = { {0, 1}, {1, 1} };
int direction2[2][2] = { {1, 0}, {1, 1} };
int direction3[3][2] = { {0, 1}, {1, 0}, {1,1} };

bool check(int y, int x) {
	if (house[y - 1][x] == 1 || house[y][x - 1] == 1) return false;
	return true;
}

void bfs(int y, int x) {

	//y, x 값이랑 어떤 상태인지. 1 2 3 중.
	queue < pair<pair<int, int>, int>> q;
	q.push({ {y, x}, 1 });
	dp[y][x] = 1;

	while (!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		//마지막에 도달했으면 더 가지 않아도 됩니다.
		if (cy == n - 1 && cx == n - 1) continue;

		switch (dir) {
		case 1:
			for (int i = 0; i < 2; i++) {
				int ny = cy + direction1[i][0];
				int nx = cx + direction1[i][1];
				int ndir;

				if (house[ny][nx] == 1 || ny>=n|| nx>=n) continue;

				if (i==1 && !check(ny, nx)) {
					continue;
				}

				ndir = i == 0 ? 1 : 3;

				dp[ny][nx] += 1;

				q.push({ {ny, nx}, ndir });
			}

			break;
		case 2:
			for (int i = 0; i < 2; i++) {
				int ny = cy + direction2[i][0];
				int nx = cx + direction2[i][1];
				int ndir;

				if (house[ny][nx] == 1 || ny >= n || nx >= n) continue;

				if (i == 1 && !check(ny, nx)) {
					continue;
				}

				ndir = i == 0 ? 2 : 3;

				dp[ny][nx] += 1;

				q.push({ {ny, nx}, ndir });
			}

			break;
		case 3:
			for (int i = 0; i < 3; i++) {
				int ny = cy + direction3[i][0];
				int nx = cx + direction3[i][1];
				int ndir;

				if (house[ny][nx] == 1 || ny >= n || nx >= n) continue;

				if (i == 2 && !check(ny, nx)) {
					continue;
				}

				if (i == 0) ndir = 1;
				else if (i == 1) ndir = 2;
				else ndir = 3;

				dp[ny][nx] += 1;
				q.push({ {ny, nx}, ndir });
			}

			break;
		default:
			break;
		}
	}
}

void printDP() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> house[i][j];
		}
	}

	bfs(0, 1);

	//printDP();

	cout << dp[n - 1][n - 1] << '\n';

	return 0;
}
