#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
19.06.08.토.
greedy.
사과 담기 게임. 바구니의 길이에 따라 위치를 조정하면 됨.
*/

int main()
{
	int n, m; //칸의 너비와 바구니의 크기
	cin >> n >> m;
	int j; //떨어지는 사과의 수
	cin >> j;

	vector<int> pos; //사과의 위치를 담음.
	int p;

	for (int i = 0; i < j; i++) //사과의 수만큼 위치를 저장
	{
		cin >> p;
		pos.push_back(p);
	}

	int l = 1;//맨 왼쪽 자리는 처음에 1
	int r = m;//맨 오른쪽 자리는 처음에 바구니의 길이

	int cnt = 0; //이동한 횟수
	int get = 0; //사과 몇 개를 담았는가
	while (1)
	{
		if (r < pos[get]) //오른쪽 이동
		{
			l++;
			r++;
			cnt++;
		}
		else if(l>pos[get]) //왼쪽 이동
		{
			l--;
			r--;
			cnt++;;
		}
		else // 사과를 담을 수 있음
		{
			get++;
			if (get == j) // 사과를 모두 담았으면 종료.
				break;
		}
	}

	// 몇 번 움직였는지 출력.
	cout << cnt << endl;

	return 0;
}
