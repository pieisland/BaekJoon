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
int coin[100 + 1];
int value[10000 + 10];
long long dp[100000 + 10];
int INF = 9876543210;

/*
구하는 동전의 가치보다 더 큰 값의 동전을 넣는 걸 생각해야했다. 런타임 에러가 나버림.

dp의 의미는 그 값을 만들기 위해 필요한 최소 동전의 수.
초기 값을 INF로 주고 해당 동전이 바로 있다면 1로 설정해준다.  

dp 값을 최소로 계속 갱신한다.
만들 수 없다면 INF 이상의 값이 나오게 되는데 그 때는 INF로 정정해주었다.

bottom up..
*/

int main() {

	cin >> n >> k;

	for (int i = 0; i <= k; i++) {
		dp[i] = INF;
	}

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		dp[coin[i]] = 1;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
			if (dp[i] > INF) dp[i] = INF;
		}
	}

	if (dp[k] >= INF)
		cout << -1 << '\n';
	else cout << dp[k] << '\n';

	return 0;
}
