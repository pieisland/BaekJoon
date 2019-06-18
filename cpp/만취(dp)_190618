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
..? 그냥 웃으면서 푸는 문제.
*/

int room[101];

int play(int num)
{
	memset(room, 0, sizeof(room));//0을 잠근 거라고 하면
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			if (j%i == 0)
				room[j] = !room[j];

	int cnt = 0;
	for (int i = 1; i <= num; i++)
		if (room[i] == 1)//1이 연 것
			cnt++;
	return cnt;
}

int main(){

	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout<<play(n)<<endl;
	}

	return 0;
}
