#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
19.06.22.토.
빙산 문제. 혹시 시간 초과가 될까봐 걱정했는데, 그렇지는 않았음.
빙산을 녹일 때, 모든 빙사이 살아있는 부분에서 빙산이 살아있는 채로 확인을 하고
녹인 결과를 temp에 저장한 후에 결과를 바꿔야 한다.
*/

int n, m;
int arr[300][300];
int temp[300][300];
int check[300][300];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isInside(int y, int x)
{
	if (y >= 0 && y < n&&x >= 0 && x < m)
		return true;
	else
		return false;
}

void melting()
{
	//모든 빙산들에 대해서 양 옆의 0개수를 세어, 녹인다.
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] != 0)
			{
				int zero = 0;
				//사방에 있는 0의 개수를 센다.
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dir[k][0];
					int nx = j + dir[k][1];
					if (isInside(ny, nx) && arr[ny][nx] == 0)
						zero++;
				}
				//temp에 따로 저장을 하고 바꿔줘야 함. 빙산이 한 순간에 같이 녹기 때문.
				temp[i][j] = arr[i][j] - zero;
				//움수가 됐다면 0으로 해줌.
				if (temp[i][j] < 0)
					temp[i][j] = 0;
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = temp[i][j];
	
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;*/
}

void bfs(int y, int x) {
	
	queue<pair<int, int>> q;
	q.push(pair<int, int>(y, x));

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (isInside(ny, nx) && check[ny][nx] == 0&&arr[ny][nx] != 0)
			{
				check[ny][nx] = 1;
				q.push(pair<int, int>(ny, nx));
			}
		}
	}
}

int main(){
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int ans = 0;
	while (1)
	{
		//빙산이 녹는다. 문제에서 한 덩어리의 빙산이 주어지므로 맨 처음에 녹이고 확인해도 됨.
		memset(check, 0, sizeof(check));

		melting();
		ans++;

		int cnt = 0;
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				//빙산이 남아있는 곳이고, 방문하지 않았다면
				if (arr[i][j] != 0 && check[i][j] == 0)
				{
					cnt++;
					check[i][j] = 1;
					bfs(i, j);
				}
			}

		//두 덩이인지 확인한다.
		if (cnt >= 2)
		{
			cout << ans << endl;
			break;
		}

		//다 녹았으면 0덩이. 처음에는 1이기 때문에 문제 안 생김.
		if (cnt == 0)
		{
			cout << 0 << endl;
			break;
		}
	}

	return 0;
}
