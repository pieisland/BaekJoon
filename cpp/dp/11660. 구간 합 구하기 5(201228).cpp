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
ios base 하는 거 안 써서 시간 초과가 한 번 떴다.
그래서 scanf를 쓰는 게 좋기는 하다..

제일 중요한 건 맨 처음에 누적합을 구하는 부분이다.
dp[i][j] 값을 dp[i-1][j] dp[i][j-1] dp[i-1][j-1]로 구하는 부분.
그부분만 이해하면 쉽다.
*/

int n, m;
int table[1024 + 1][1024 + 1];
int dp[1024 + 1][1024 + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >>m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> table[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + table[i][j];
		}
	}

	int y1, x1, y2, x2;
	for (int i = 0; i < m; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		int answer = dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
		cout << answer << '\n';
	}

	return 0;
}
