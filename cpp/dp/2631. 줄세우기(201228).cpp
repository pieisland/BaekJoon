#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n;
int row[200];
int dp[200];

/*
이게 최장 증가 수열 문제였다니....
longest increasing subsequence
라고 해서, 최장 증가 길이를 찾고.
거기에 포함되는 값들은 제대로 정렬이 되어있는 것이기 때문에
안 움직여도 되는 값이 되고,
아닌 값들은 움직여야 해서 n에서 lislength를 빼면 정답.
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> row[i];
	}

	int lisLength = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] == 0) dp[i] = 1;
		for (int j = 0; j < i; j++) {
			//내 앞에 있는 값이 나보다 작다면 제대로 정렬이 돼있는 것
			if (row[i] > row[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					if (dp[i] > lisLength)
						lisLength = dp[i];
				}
			}
		}
	}

	cout << n - lisLength << '\n';
	//printDP();

	return 0;
}
