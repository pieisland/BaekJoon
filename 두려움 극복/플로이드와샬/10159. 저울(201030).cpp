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
호기롭게 기본 floyd로 풀었는데
한쪽 방향으로 가는 것만 count를 하다보니.. 틀림.

(i,j) (j,i) 중에 하나라도 가능하면 비교할 수 있는 거라고 구한 뒤에
전체에서 빼주면 되는 거였다.

1을 더 빼주는 이유는 자기 자신은 비교하지 않기 때문이다.

ㅇ.
*/

int n, m;
int connect[101][101];
int INF = 987654321;

void printConnect() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << connect[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			connect[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		connect[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (connect[i][k] + connect[k][j] < connect[i][j]) {
					connect[i][j] = connect[i][k] + connect[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (connect[i][j] < INF  || connect[j][i]<INF) {
				cnt++;
			}
		}
		cout << n - cnt-1 << '\n';
	}

	return 0;
}
