#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//출처: https://yabmoons.tistory.com/154
//2020.10.22

int n;
int forest[500][500];
int dp[500][500]; //내가 시작날일 때 최대로 살 수 있는 날을 저장.
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isinside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	else return false;
}

int move(int y, int x) {
	//이미 가서 확인한 곳은 값만 return하자.
	if (dp[y][x] != 0) return dp[y][x];
	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (isinside(ny, nx)) {
			if (forest[y][x] < forest[ny][nx]) {
				//더 먹을 수 있는 대나무라면
				int val = move(ny, nx);
				dp[y][x] = dp[y][x] < val + 1? val+1 : dp[y][x];
			}
		}
	}

	return dp[y][x];
}

int main(void){

	cin >> n;
	int answer = 0;

	for (int i= 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}

	//모든 위치에서의 최소 날을 구해서 가장 큰 날을 찾는다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ret = move(i, j);
			if (answer < ret) answer = ret;
		}
	}

	cout << answer << '\n';

	return 0;
}
