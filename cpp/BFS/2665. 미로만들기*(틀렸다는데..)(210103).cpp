#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
솔직히 왜 틀렸다는지 모르겠음.
이해를 할 수가 없다.. 아니 잘만 나오는데.
무슨 % 올라가는 것도 아니고 그냥 바로 틀렸다고 함.

암튼 틀렸다고 뜨긴 했지만, 이 문제에서 얻어갈 게 있어서 적어둔다.

어떤 검은 방을 부술지를 미리 결정하는 게 아니라
일단 부수고 간다고 생각하고 부순 후에
크기 비교해서 갱신해나가는 문제였다.
신선.
*/

int n;
int miro[51][51];
int crash[51][51];
int INF = 987654321;
int answer = INF;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isinside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	else return false;
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			crash[i][j] = INF;
		}
	}
	
	crash[0][0] = 0;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		/*if (cy == n - 1 && cx == n - 1) {
			if(crash[cy][cx] < answer) answer = crash[cy][cx];
			continue;
		}*/

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (isinside(ny, nx)) {
				if (miro[ny][nx] == 1) {
					if (crash[cy][cx] < crash[ny][nx]) {
						crash[ny][nx] = crash[cy][cx];
						q.push({ ny, nx });
					}
				}
				else {//검은방..
					if (crash[cy][cx]+1 < crash[ny][nx]) {
						crash[ny][nx] = crash[cy][cx]+1;
						q.push({ ny, nx });
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &miro[i][j]);
		}
	}

	bfs(0, 0);

	cout << crash[n-1][n-1] << endl;

	return 0;
}
