#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
19.06.12.수.
3중 for문을 사용하지 않는 방법은 없나?
점화식을 세운 문제.
*/

int arr[1001];
int dp[1001][10];

int main(void)
{
	int n;
	cin >> n;

	//1자리 수에서 마지막 수가 i일 때 만들 수 있는 개수.
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
        //길이가 i자리인 수에서 마지막 수가 j일 때 i-1자리의 수에서 처음부터 j까지 경우를 더해야 함.
        //적어보면 보임.
				dp[i][j] += dp[i - 1][k]%10007;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans += dp[n][i]%10007;

	cout << ans%10007 << endl;

	return 0;
}
