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
제일 큰거에서 시작해서 쪼개는 문제였다.
하하하하.
이렇게 풀면 시간 초과가 안나구나....
사실 차이는 잘 모르겠는데.

아무튼간에 사이즈만큼 확인을 하다가 처음 색이랑
다른 색이라면 멈추고 바로 4개로 쪼개어서 재귀를 돌리고
끝까지 같은 색만 봤다면 그 색 개수를 1증가 해준다.
*/

int n;
int paper[128][128];
int check[128][128];
int blueCnt;
int whiteCnt;

void solve(int y, int x, int size) {
	int color = paper[y][x];
	bool check = true;

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (paper[i][j] != color) {
				//다른 색이라면 어떻게 하죠?
				check = false;
				break;
			}
		}

		if (!check) {
			break;
		}
	}

	if (!check) {
		solve(y, x, size / 2);
		solve(y, x + size / 2, size / 2);
		solve(y + size / 2, x, size / 2);
		solve(y + size / 2, x + size / 2, size / 2);
	}
	else {
		if (color == 1) {
			blueCnt++;
		}
		else {
			whiteCnt++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	solve(0, 0, n);

	cout << whiteCnt << '\n';
	cout << blueCnt << '\n';

	return 0;
}
