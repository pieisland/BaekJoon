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

3중 for문이라서 괜찮을까 했지만 다행히 통과!
i번째에 대해서
이전 위치에서 뛰어서 이동할 수 있는지를 확인하고
dp 값을 비교해서 더 작으면 갱신해준다.
*/

int n;
int miro[1001];
int dp[1001]; //최소 몇 번으로 여기 왔는가.. 아닐까.
int INF = 987654321;

void printDP() {
	for (int i = 0; i < n; i++) {
		cout << dp[i] << ' ';
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> miro[i];
		dp[i] = INF;
	}
	
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 1; k <= miro[j]; k++) {
				if (i == j + k) {
					//j에서 k로 올 수 있을 때
					if (dp[i] > dp[j] + 1) {
						dp[i] = dp[j] + 1;
					}
				}
			}			
		}
	}

	if (dp[n - 1] == INF)
		dp[n - 1] = -1;
	cout << dp[n - 1] << '\n';

//	printDP();

	return 0;
}
