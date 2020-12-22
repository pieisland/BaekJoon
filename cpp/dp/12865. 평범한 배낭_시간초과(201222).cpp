#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n, k;
int stuff[100][2];//0은 무게 1은 가치
int dp[100000 + 10];//해당 무게일 때의 가치의 합
//마지막에 for문 돌면서 제일 큰 거 구하면 됨.

int main() {

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, v; //무게와 가치
		cin >> w >> v;
		stuff[i][0] = w;
		stuff[i][1] = v;
		dp[w] = v; //무게일 때의 가치.
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}

	int ans = 0;
	for (int i = 0; i <= k; i++) {
		ans = dp[i] > ans ? dp[i] : ans;
	}
	cout << ans << '\n';

	return 0;
}
