#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
19.06.19.수.
왜 bfs문제인지 모르겠던데, 이런 형태도 bfs가 된다는 게 신기했음.
출처: https://jaimemin.tistory.com/645
다른 문제와는 dir 배열을 while문에서 결정을 하는 것?? 하하. 아무튼 조금 생소.
전역변수로 할 수가 없어서 bfs내에서 만들어야 했다.
*/

int f, s, g, u, d;
int c[1000001];//방문한 층인지를 확인함. 재방문 하지 않으므로.
int ans;
//아. 입력을 받아서 결정이되는 수로 만들 수는 없구나..

int bfs()
{
	queue<int> q;
	q.push(s);
	c[s] = 1;

	while (!q.empty())
	{
		int cs = q.front();
		q.pop();

		if (cs == g)//목표 층에 도달
			return c[cs] - 1;

		//다음 위치가 층의 위치에 따라 변화..
		int next[2] = { cs + u, cs - d };

		for (int i = 0; i < 2; i++)
		{
			//1층에서 맨 윗 층 사이에 있으며, 아직 가지 않은 층이라면
			if (1 <= next[i] &&next[i] <= f && c[next[i]] == 0)
			{
				c[next[i]] = c[cs] + 1;
				q.push(next[i]);
			}
		}
	}
	return -1;
}

int main(){

	cin >> f >> s >> g >> u >> d;
	int ans = bfs();

	if (ans == -1)
		cout << "use the stairs" << endl;
	else
		cout << ans << endl;

	return 0;
}
