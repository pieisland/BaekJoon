#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int n;
int arr[500][500];
int dp[500][500];
vector<int> ans;

/*
19.06.06.
dp로 안풀면 메모리 초과된다.
아니 진짜 짜증나는게..
dp에 대한 뭔가 이미지가 잘못박혀서 문제 해결이 어려움.
2차원 배열의 이용과 구한 값에서 최대를 찾는 게 후.. 
*/

void func(int a, int b, int sum)
{
	if (a + 1 < n)
	{
		func(a + 1, b, sum + arr[a + 1][b]);
		func(a + 1, b + 1, sum + arr[a + 1][b + 1]);
	}
	else
		ans.push_back(sum);
}

int main()
{	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)//맨 왼쪽이라면 오른쪽 위의 값만 고려
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (j == i)//맨 오른쪽이라면 왼쪽 위의 값만 고려
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			else//나머지들, 중간에 있는 경우 왼쪽 위, 오른쪽 위 값과 현재 값의 합 중 최대값을 저
				dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i - 1][j - 1] + arr[i][j]);
		}
	}

	//func(0, 0, arr[0][0]);
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (dp[n - 1][i] > max)
			max = dp[n - 1][i];
	}

	//sort(ans.begin(), ans.end());
	//cout << ans[ans.size() - 1];

	cout << max << endl;

	return 0;
}
