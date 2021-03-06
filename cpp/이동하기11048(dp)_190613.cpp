#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
19.06.13.목.
위치와 관련해서 범위에 벗어나는 것을 쉽게 해결할 수 있는 방법은
인덱스를 +1을 해서 0번쨰를 0으로 만들어주는 것.

그 위치에 대한 최대값을 계속 갱신해나간다.
*/

int arr[1001][1001];
int dp[1001][1001];

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			//사실 dp[i-1][j-1]은 나머지 두 개보다 작을 수 밖에 없어서 고려하지 않아도 된다. 사탕이 양수이기 때문.
			dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
			dp[i][j] += arr[i][j];
		}
	}

	cout << dp[n][m] << endl;

	return 0;
}
