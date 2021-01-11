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
열심히.. 생각해보면 되는 문제인데.
될 것 같으면서도 귀찮은 느낌이 물씬 나는 문제.

일단 가능하다 아니다를 판단할 때
지금 내 숫자와 다음에 나타나는 숫자를 비교해서
나보다 크면은 넘어가고(새로 넣으면 됨)
나보다 작은데 그전까지 찾은 숫자보다 크다면 순서가 안 맞은 거라서
possible을 false로 바꾸고 끝낸다.

출력을 할 때는 
실제로 vector에 넘으면서 했다.
비어있거나 마지막에 있는 수보다 크다면 그 수가 될 때까지
넣어주고
마지막에 빼준다.
*/

int n;
int paper[128][128];
int check[128][128];
int blueCnt;
int whiteCnt;

int dfs(int y, int x, int color) {
	//마지막 처리
	if (y > n || x > n) return 0;
	//같은 색 아님
	if (paper[y][x] != color) return 0;

	int v1 = dfs(y, x + 1, color);
	int v2 = dfs(y + 1, x, color);
	int v3 = dfs(y + 1, x + 1, color);

	int minval = min(v1, min(v2, v3));

	//아니 레알 이거 비슷한 문제 풀었던 것 같은데;
	//dp 문제로 풀지 않았음..? 제일 큰 사각형 찾는 거였나 뭐였나 그런 문제로.

	return minval + 1;
}

void doCheck(int y, int x, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			check[i][j] = 1;
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				int val = dfs(i, j, paper[i][j]);
//				cout << val << '\n';
				doCheck(i, j, val);

				if (paper[i][j] == 1) {
					blueCnt++;
				}
				else whiteCnt++;
			}
		}
	}

	cout << whiteCnt << '\n';
	cout << blueCnt << '\n';

	return 0;
}
