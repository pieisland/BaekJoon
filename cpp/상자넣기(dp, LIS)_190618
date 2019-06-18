#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
2019.06.18.화.
LIS랑 똑같은 문제.
*/

int arr[1000];
int dp[1000];

int main(){

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		if (dp[i] == 0)dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i])// 앞에 게 작아야 뒤 상자에 넣음
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
	}
	sort(dp, dp + n);

	cout << dp[n - 1] << endl;

	return 0;
}
