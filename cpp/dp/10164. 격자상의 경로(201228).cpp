#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n, m, k;
int dp[16][16];

/*
분명히 많이 풀어본 형태의 문제인데... 잘 안풀리네.

몫과 나머지를 좀 생각해야 하는 문제였다.
그게 헷갈리고. 다른 부분은 일반적인 dp 문제와 같다고 보면 될 듯...
*/

void printDP() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cout << dp[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	
	//꼭 거쳐야 하는 곳이 없음
	if (k == 0) {
		//(1,1)에서 (n,m) 까지 가는 경우의 수를 구한다.
		//정답은 dp[n][m]
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				if (i == 1 && j == 1) dp[i][j] = 1;
			}
		}
	}
	else { //있음.
		int y = 1, x;
		int moc = k / m;
		int nam = k % m;
		if (nam == 0) {
			y += moc - 1;
			x = m;
		}
		else {
			y += moc;
			x = nam;
		}

		dp[1][1] = 1;
		for (int i = 1; i <= y; i++) {
			for (int j = 1; j <= x; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				if (i == 1 && j == 1) dp[i][j] = 1;
			}
		}

		for (int i = y; i <= n; i++) {
			for (int j = x; j <= m; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	//printDP();

	cout << dp[n][m] << '\n';

	return 0;
}
