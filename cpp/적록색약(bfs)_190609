#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
19.06.09.일.
기본 문제. 
*/

int n;
char arr[100][100];
int c[100][100];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int ans;
int ans2;

bool isInside(int y, int x)
{
	if (y >= 0 && y < n&&x >= 0 && x < n)
		return 1;
	else
		return 0;
}

void bfs(int a, int b)
{
	queue <pair<int, int>> q;
	q.push(pair<int, int>(a, b));

	char color = arr[a][b];
	ans++;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		c[cy][cx] = 1;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];
			//안에 있고, 방문하지 않았으며, 동일한 색깔이라면
			if (isInside(ny, nx) && c[ny][nx] == 0 && arr[ny][nx] == color)
			{
				c[ny][nx] = 1;
				q.push(pair<int, int>(ny, nx));
			}
		}
	}
}

int main(){

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (c[i][j] == 0)
			{
				bfs(i, j);
			}
		}
	}

	cout << ans << " ";

	//적록색약 초기화
	ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = 0;

	//G를 R로 변경.
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] == 'G')
				arr[i][j] = 'R';

	//적록색약 bfs
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (c[i][j] == 0)
				bfs(i, j);
		}
	}

	cout << ans << endl;

	return 0;
}
