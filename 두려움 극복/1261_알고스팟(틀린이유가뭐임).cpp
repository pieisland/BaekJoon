#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int miro[101][101];
int cnt[101][101];
int INF = 987654321;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int n, m;

bool isinside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	else return false;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {			
			scanf("%1d", &miro[i][j]);
			cnt[i][j] = INF;
		}
	}

	cnt[0][0] = 0;

	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, {0, 0} });

	while (!pq.empty()) {
		int cy = pq.top().second.first;
		int cx = pq.top().second.second;
		int cCnt = -pq.top().first;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];
			if (isinside(ny, nx)) {
				//cout << ny << ' ' << nx << endl;
				int newCnt=cCnt;
				if (miro[ny][nx] == 1) {
					newCnt += 1;
				}
				//cout << cnt[ny][nx] << " " << newCnt << endl;
				if (cnt[ny][nx] > newCnt) {
					cnt[ny][nx] = newCnt;
					pq.push({ -newCnt, {ny, nx} });
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << cnt[i][j];
		}
		cout << '\n';
	}

	cout<< cnt[n-1][m-1]<<'\n';

	return 0;
}
