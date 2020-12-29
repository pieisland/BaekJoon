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
적어보면 아는 문제
*/

int k;
int dp[45+1][2];

void printDP() {
	/*for (int i = 0; i <= s; i++) {
		cout << dp[i] << ' ';
	}
	cout << endl;*/
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> k;
	dp[0][0] = 1;
	dp[0][1] = 0;

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= k; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	cout << dp[k][0] << ' ' << dp[k][1] << '\n';

	return 0;
}
