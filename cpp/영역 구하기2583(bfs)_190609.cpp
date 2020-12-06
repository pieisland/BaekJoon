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
기본적인 bfs 문제.
*/

int c[100][100];
int arr[100][100];
int n, m, k;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<int> answer;

bool isInside(int x, int y)
{
	if (x >= 0 && x < n&&y >= 0 && y < m)
		return 1;
	else
		return 0;
}

void bfs(int x, int y)
{
	//c[x][y] = 1;
	int cnt = 0;
	queue <pair<int, int>> q;
	q.push(pair<int, int>(x, y));

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		c[cx][cy] = 1;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dir[i][0];
			int ny = cy + dir[i][1];
			if (isInside(nx, ny) && c[nx][ny] == 0 && arr[nx][ny] == 0)
			{
				q.push(pair<int, int>(nx, ny));
				c[nx][ny] = 1;
			}
		}
	}
	answer.push_back(cnt);
}

void rec(int x1, int y1, int x2, int y2)
{
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
			arr[i][j] = 1;
}

int main(){
	cin >> m >> n >> k;
	
	int ans = 0;
	int x1, y1, x2, y2;
	for (int i = 0; i < k;i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		rec(x1, y1, x2, y2);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cout << arr[i][j] << ' ';
			if (c[i][j] == 0 && arr[i][j] == 0)
			{
				ans++;
				bfs(i, j);
			}
		}
		//cout << endl;
	}

	cout << ans << endl;
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';

	return 0;
}
