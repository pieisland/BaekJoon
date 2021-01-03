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
저울 문제랑 되게 비슷한 것 같은데..
*/

int n, m;
int conn[501][501];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		conn[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
        //건너서 연결돼있으면 나도 연결돼있다.
				if (conn[i][k] && conn[k][j]) conn[i][j] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;//같은 건 제외하고
      //a->b 또는 b->a로 연결이 안돼있으면 연결안돼있다.
			if (conn[i][j] == 0 && conn[j][i] == 0)
				cnt++;
		}
		if (cnt == 0) ans++;
	}

	cout << ans << '\n';

	return 0;
}
