#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n, m; //1000이 최대
int dp[1000][1000];//i, j에서 시작한 최대 정사각형 크기..
int arr[1000][1000];
int ans;

void printDp() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
}

int recur(int y, int x) {

	/*if (y > n || x > m) {
		return arr[y][x];
	}*/
	if (y > n || x > m) return 0;

	int squareValue = min(recur(y + 1, x), min(recur(y, x + 1), recur(y + 1, x + 1)));
	//cout << dp[y][x] + squareValue << '\n';
	//dp[y][x] += squareValue;
	if (ans < dp[y][x] + squareValue) ans = dp[y][x] + squareValue;
	return dp[y][x] + squareValue;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j]) dp[i][j] = 1;
		}
	}

	/*for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (dp[i][j]==0 || dp[i + 1][j] == 0 || dp[i][j + 1] == 0 || dp[i + 1][j + 1] == 0)
				continue;
			int squareSize = min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
			dp[i][j] += squareSize;
		}
	}
	*/

	recur(0, 0);

	//printDp();

	/*int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answer = max(answer, dp[i][j]);
		}
	}*/

	cout << ans*ans << '\n';

	return 0;
}
