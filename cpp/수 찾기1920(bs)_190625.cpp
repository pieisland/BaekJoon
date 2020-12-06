#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
2019.06.25.화.
이진탐색 숫자찾기.
근데.. cin.tie(NULL);
이랑 endl 대신에 \n을 쓰는게
왜 속도가 향상이 되는건지.. 모르겠네.
*/

vector<int> number;

int BSearch(int target)
{
	int low = 0;
	int high = number.size() - 1;
	
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (number[mid] == target)
			return 1;
		else if (number[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

int main(){

	int n, m;
	cin.tie(NULL);
	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		number.push_back(tmp);
	}
	sort(number.begin(), number.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		cout << BSearch(tmp) << '\n';
	}

	return 0;
}
