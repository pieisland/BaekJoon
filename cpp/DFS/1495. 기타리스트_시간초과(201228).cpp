#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n, s, m;
int sound[101];

//dp의 의미가 지금 뭘까??
int dp[101];
int answer = -10;

void dfs(int index, int nowVolume) {
	if (nowVolume > m) return;
	if (nowVolume < 0) return;
	
	if (index == n) {
		if (answer < nowVolume) {
			answer = nowVolume;
			return;
		}
	}

	dfs(index + 1, nowVolume + sound[index]);
	dfs(index + 1, nowVolume - sound[index]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//n개의 곡, 스타트 볼륨 s, 볼륨 최댓값 m
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> sound[i];
	}

	dfs(0, s);

	if (answer >= 0)
		cout << answer << '\n';
	else
		cout << -1 << '\n';
	//printDP();

	return 0;
}
