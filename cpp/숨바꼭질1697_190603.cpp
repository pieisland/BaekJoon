#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/*
19.06.03.월.
처음으로 혼자 푼 bfs. 이전 문제랑 비슷해서 풀 수 있었다. ㅎ.ㅎ
bfs는 스스로 최소값을 찾아주는 것 같다. 이때까지 본 바에 의하면.
그러기 위해선 지나간 곳에 대해 표시를 해야 하고,
얼마나 지나갔는지를 알기 위해선 그 표시를 한 곳을 이용하면 편하다.
움직일 수 있는 세 개에 대해서 각각 조건을 줘서 해결했다.
*/

//그냥 배열에 갈 수 있는 경로를 넣어둔 다음에 for문 돌면서 확인해도 되겠다
//세 경우를 넣고. p에도 시작 위치에 1을 넣은 후에 마지막에 결과에서 -1 하면 될 것.

int n, k;
int p[100001];

void bfs(int num)
{
	queue<int> q;
	q.push(num);
	p[num] = 0;//이 문제의 경우, 처음 위치는 움직인 게 아니므로 0.
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		//동생과 같은 지점일 경우
		if (x == k)
		{
			cout << p[x];
			break;
		}

		if (x - 1 >= 0 && p[x - 1] == 0)
		{
			q.push(x - 1);
			p[x - 1] = p[x] + 1;
		}
		if (x + 1 <= 100000 && p[x + 1] == 0)
		{
			q.push(x + 1);
			p[x + 1] = p[x] + 1;
		}
		if (2 * x <= 100000 && p[2 * x] == 0) 
		{
			q.push(2 * x);
			p[2 * x] = p[x] + 1;
		}
	}
}

int main()
{
	cin >> n >> k;

	bfs(n);

	return 0;
}
