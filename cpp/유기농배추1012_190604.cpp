#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/*
19.06.04.화.
단지번호붙이기랑 똑같은 문제라고 봐도 무방.
차이는 재사용을 하기 떄문에 초기화를 다시 해줘야된다는 것.
초기화 안해서 2번이나 틀림.. ^.^
*/

//일반적으로 bfs로 푸는데 이 때는 dfs로 풀었었네.

int m, n;
int check[50][50];
int land[50][50];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int ans;

bool isInside(int y, int x)
{
	if (y >= 0 && y < m&&x >= 0 && x < n)
		return 1;
	else
		return 0;
}

void dfs(int y, int x)
{
	check[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (isInside(ny, nx) && check[ny][nx] == 0 && land[ny][nx] == 1)
			dfs(ny, nx);
	}
}

void landArange(int m, int n, int c) {
	
	//재사용 할 것이므로 땅을 초기화
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			land[i][j] = 0;
			check[i][j] = 0;
		}
	}

	int y, x;

	for (int i = 0; i < c; i++)
	{
		cin >> y >> x;
		land[y][x] = 1;//배추가 있음을 표시
	}
}

int main()
{	
	int cnt;
	cin >> cnt;
	
	vector<int> answer;

	int c;
	for(int i=0;i<cnt;i++)
	{
		cin >> m >> n >> c;
		landArange(m, n, c);
		
		ans = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (check[i][j] == 0 && land[i][j] == 1)
				{
					ans++;
					dfs(i, j);
				}
			}
		}
		answer.push_back(ans);
	}

	//cout << cnt<<"문제있음..?"<<endl;
	for (int i = 0; i < cnt; i++)
		cout << answer[i] << endl;

	return 0;
}
