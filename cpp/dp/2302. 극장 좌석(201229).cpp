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
20.12.29
도대체 무슨 문제냐 했는데 알고보면 피보나치인, 규칙이 있는 문제가 많은 것 같다.
헷갈리는 부분은 범위 개수를 구하는 부분이었다.
좀 더 깔끔하게 할 수 있을 것 같기는 한데 생각이 안난다.
*/

int n, m;
int dp[41];
int pos[41];

void printDP() {
	for (int i = 0; i <= n; i++) {
		cout << dp[i] << ' ';
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		pos[t] = 1;
	}

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

//	printDP();

	if (m == 0) {
		cout << dp[n] << '\n';
	}
	else {
		int startIndex = 0;
		int answer = 1;
		for (int i = 1; i <= n; i++) {
			if (pos[i]) {
				answer *= dp[i-startIndex-1];
				startIndex = i;
			}
		}
		answer *= dp[n - startIndex];
		cout << answer << '\n';
	}


	return 0;
}
