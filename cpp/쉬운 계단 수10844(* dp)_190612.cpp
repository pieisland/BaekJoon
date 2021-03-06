#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
#define mod 1000000000

/*
19.06.12.수.
*/
long long int dp[101][10];

int main(void)
{
	int n;
	cin >> n;

	//사실 뒤에 붙이는 거로만 고려하고 0과 9를 조심하면 되는 문제

	//길이가 1이고 마지막 숫자가 i일 때의 개수
	//행렬을 이런 식으로 보기 힘들어서 더 힘들어짐..
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0) //마지막 숫자가 0이면, 1을 뒤에 붙이는 방법 뿐
				dp[i][j] = dp[i - 1][j + 1]%mod;
			else if(j==9) //마지막 숫자가 9이면 8을 뒤에 붙이는 방법 뿐
				dp[i][j] = dp[i - 1][j - 1]%mod;
			else //아니라면 i-1이나 i+1을 뒤에 붙이면 된다.
				dp[i][j] = (dp[i - 1][j + 1]+dp[i-1][j-1])%mod;
		}
	}

	long long int sum = 0;
        //길이가 n이 수에서 마지막 숫자가 0에서 9까지 되는 수를 모두 더하면 정답.
	for (int i = 0; i <= 9; i++)
		sum = (sum + dp[n][i])%mod;

	cout << sum % mod << endl;

	return 0;
}
