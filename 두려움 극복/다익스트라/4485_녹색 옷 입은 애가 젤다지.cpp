#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//2020.10.22.목.

int n;
int cave[126][126];
int dist[126][126];
int INF = 987654321;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void initDist() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
		}
	}
}

bool isinside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	else return false;
}

void dijkstra() {
	initDist();
	dist[0][0] = cave[0][0];

	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -dist[0][0], {0, 0} });

	while (!pq.empty()) {
		int cy = pq.top().second.first;
		int cx = pq.top().second.second;
		int value = -pq.top().first;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (isinside(ny, nx)) {
				int nextVal = value + cave[ny][nx];
				if (dist[ny][nx] > nextVal) {
					//cout << "왜 안돼.." << endl;
					dist[ny][nx] = nextVal;
					pq.push({ -nextVal, {ny, nx} });
				}
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	while (1) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cave[i][j];
			}
		}

		dijkstra();

		cnt++;
		cout << "Problem "<<cnt<<": "<<dist[n - 1][n - 1] << '\n';
	}

	return 0;
}
