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
bfs로 가능한 모든 경우를 돌리는 문제.
bfs가 최단 경로를 찾아준다는 걸 상기하게 된 문제.
*/

char arr[50][50];
int c[50][50];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int n, m;
int ans;

bool isInside(int y, int x)
{
	if (y >= 0 && y < n&&x >= 0 && x < m)
		return true;
	else
		return false;
}

void show()
{
	int tmp = -1;
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}*/

	//초기화를 해주고
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (tmp < c[i][j])
				tmp = c[i][j];
			c[i][j] = 0;
		}
	}

	//cout << tmp << endl;
	//현재 tmp에는 가장 큰 c값이 있기 때문에, 그 값에서 1을 뺀 것이 정답이 될 것입니다.
	if (ans < tmp)
		ans = tmp;

	//cout << endl;
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(pair<int, int>(y, x));

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
			if (isInside(ny, nx)&&arr[ny][nx] == 'L' && c[ny][nx] == 0)
			{
				q.push(pair<int, int>(ny, nx));
				c[ny][nx] = c[cy][cx] + 1;
			}
		}
	}
	show();
}

int main(){

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}

	//최단거리에서 가장 먼 곳이라.
	//그렇다면..?? 모든 경우의 수에 대해서 1로 주고 시작을 해봐야할 것 같다.
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			if (c[i][j] == 0 && arr[i][j]=='L') {
				cout << i << " " << j<<endl;
				c[i][j] = 1;
				bfs(i, j);	
			}
			//이게 어차피, 다아아아 끝난 후에 측정을 하기 때문에 괜찮다.
		}
	if (ans >= 1)
		cout << ans - 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}
