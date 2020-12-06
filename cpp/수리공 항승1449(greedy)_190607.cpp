#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
19.06.07.금.
테이프를 붙이는 위치를 언제 변경해주는지 생각해야 하는 문제.
*/

int n, l;
vector<int> pos;

int main()
{
	cin >> n >> l;
	int p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		pos.push_back(p);
	}

	//혹시 모르니까 sorting
	sort(pos.begin(), pos.end());

	int ans = 1;
	int last_idx = 0;
	for (int i = 1; i < n; i++)
	{
		if (pos[last_idx] - 0.5 + l < pos[i] + 0.5)//테이프를 붙여야 되는 상황
		{
			ans++;
			last_idx = i;//새로 붙여야 될 때, 테이프의 시작 위치를 변경.
			//cout << last_idx << endl;
		}
		//새로 안 붙여도 되는 경우는 이미 붙인 스티커로 감싸진 경우
	}
	
	cout << ans;

	return 0;
}
