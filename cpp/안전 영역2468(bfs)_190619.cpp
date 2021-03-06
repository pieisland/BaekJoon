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
bfs를 여러 번 돌려야 되는 문제.
*/

int arr[100][100];
int temp[100][100];
int c[100][100];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int n;

void drown(int num)
{
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] <= num)
				temp[i][j] = 0;//물에 잠겼습니다.
			else
				temp[i][j] = arr[i][j];
			c[i][j] = 0;//초기화. 원래 따로 함수를 만들어야겠지만.
		}
}

bool isInside(int y, int x)
{
	if (y >= 0 && y < n&&x >= 0 && x < n)
		return true;
	else
		return false;
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(pair<int, int>(y, x));

	c[y][x] = 1;


	while (!q.empty())
	{
		int cy, cx;
		cy = q.front().first;
		cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny, nx;
			ny = cy + dir[i][0];
			nx = cx + dir[i][1];
			//범위에 맞고, 잠기지 않았으며, 아직 방문하지 않았다면
			if (isInside(ny, nx) && temp[ny][nx] != 0 && c[ny][nx] == 0)
			{
				q.push(pair<int, int>(ny, nx));
				c[ny][nx] = 1;
			}
		}
	}
}

int main(){

	int min = 1000;
	int max = 0;
	int tans;
	int ans = 0;

	//그러면 얼마 이상이 물에 잠기는지는
	//말을 안해준 거구나.
	//제일 작은 숫자에서 시작해서 제일 큰 숫자까지
	//물에 잠긴다고 했을 때

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] < min)
				min = arr[i][j];
			if (arr[i][j] > max)
				max = arr[i][j];
		}

//	cout << min << max << endl;

	//제일 작은 수부터 제일 큰 수까지 물에 잠긴다고 하자.
	//그 때 수를 세어서 제일 큰 거를 반환하면 되잖아.
	for (int k = 0; k <= max; k++)
	{
		//k이하인 수들은 잠김.
		drown(k);
		tans = 0;
		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++)
			{
				if (c[i][j] == 0&&temp[i][j]!=0) {
					bfs(i, j);
					tans++;
				}
			}
		if (tans > ans)
			ans = tans;
	}

	cout << ans << endl;

	return 0;
}
