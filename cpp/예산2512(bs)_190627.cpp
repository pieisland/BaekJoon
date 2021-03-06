#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
2019.06.27.목.
줄 수 있는 돈의 최대를 찾아보자.
돈 줄 수 있는 범위는 1에서 제일 큰 돈 값.
배당하려는 돈보다 요구한 돈이 적거나 같다면 요구한 돈을 더하고
요구하는 돈이 많다면 배당하려는 돈만큼 준다.
총 얼마를 줬는지를 더해 가지고 있는 자본금과 비교한다.
자본금보다 적게 줬으면 더 줄 수 있도록 높여보고
자본금보다 많이 줬으면 낮춘다.
*/

//값을 high라고 할 게 아니라 다 합한 값이 총 예산보다 적거나 같을 때 result에 mid 값을 저장해주면 된다.

int n, k;
vector<int> mon;

int give(int money)
{
	long long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (mon[i] <= money)
			sum += mon[i];
		else
			sum += money;
	}

	//줄 수 있는 돈보다 적으면 줄 수 있는 돈을 늘려보고
	if (sum <= k)
		return 1;
	else//줄 수 있는 돈보다 많이 줬으면 줄여보고.
		return 0;//적게 잘렸으면 크기를 줄여야지.
}

int main() {

	cin.tie(NULL);
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		mon.push_back(tmp);
	}
	cin >> k;//예산

	sort(mon.begin(), mon.end());
	int low = 1;
	int high = mon[n - 1];//제일 큰 돈
	
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (give(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}

	cout << high << '\n';

	return 0;
}
