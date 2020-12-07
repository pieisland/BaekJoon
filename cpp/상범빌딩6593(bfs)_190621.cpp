#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
19.06.21.금.
*/
int l, r, c;
char arr[30][30][30];
int check[30][30][30];
int dir[6][3] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };

bool isInside(int z, int y, int x)
{
	if (z >= 0 && z < l && y >= 0 && y < r && x >= 0 && x < c)
		return true;
	else return false;
}

void bfs(int a, int b, int c)
{
	//abc는 시작점 좌표다.
	queue < pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(a, b), c));

	check[a][b][c] = 1;
	while (!q.empty())
	{
		int z, y, x;
		z = q.front().first.first;
		y = q.front().first.second;
		x = q.front().second;
		q.pop();

		if (arr[z][y][x] == 'E')
		{
			cout << "Escaped in " << check[z][y][x] - 1 << " minute(s)." << endl;
			return;
		}

		for (int i = 0; i < 6; i++)
		{
			int nz, ny, nx;
			nz = z + dir[i][0];
			ny = y + dir[i][1];
			nx = x + dir[i][2];
			if (isInside(nz, ny, nx) && check[nz][ny][nx]==0&&(arr[nz][ny][nx]=='.'||arr[nz][ny][nx]=='E'))
			{
				//주고요.
				check[nz][ny][nx] = check[z][y][x]+1;
				q.push(make_pair(make_pair(nz, ny), nx));
			}
		}
	}
	cout << "Trapped!" << endl;
	return;
}

int main(){
	while (1)
	{
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;

		memset(check, 0, sizeof(check));

		int pos[3];
		pair<int, int> bb;
		for(int i=0;i<l;i++)//층
			for(int j=0;j<r;j++)//행
				for (int k = 0; k < c; k++)//열
				{
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S')
					{
						pos[0] = i;
						pos[1] = j;
						pos[2] = k;
					}
				}

		bfs(pos[0], pos[1], pos[2]);

	}

	return 0;
}
