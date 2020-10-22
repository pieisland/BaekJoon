#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//20.10.22.목

int n, m;
int board[100][100];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int INF = 987654321;

bool isinside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	else return false;
}

//바깥 쪽은 -1로 해줍니다.
void fillBoard(int y, int x, int val) {
	queue<pair<int, int>> q;
	q.push({ y, x });
 
	while (!q.empty()) {
		int cy = q.front().first;
		int cx =q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];
			if (isinside(ny, nx) && board[ny][nx] == 0) {
				board[ny][nx] = val;
				q.push({ ny, nx });
			}
		}
	}
}

int boardCheck() {
	fillBoard(0, 0, -1);

	int idx = 2;
	int cheeze = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				fillBoard(i, j, idx);
				idx++;
			}
			else if (board[i][j] == 1) {
				cheeze++;
			}
		}
	}
	return cheeze;
}

void meltingCheese() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {

				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int ny = i + dir[k][0];
					int nx = j + dir[k][1];
					if (board[ny][nx] == -1) {
						cnt++;
					}
				}
				if (cnt >= 2) {
					board[i][j] = INF;//녹는 치즈.
				}
			}		
		}
	}
}

//치즈 녹은 후의 board 상태를 다시 표시.
void boardChange() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 1)
				board[i][j] = 0;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int answer = 0;
	while (1) {
		int cheezeCnt = boardCheck();
		if (cheezeCnt == 0)break;

		//녹는 치즈에 INF 표시해주기.
		meltingCheese();
		
		//치즈 녹아서 다시 0, 1로만 돼있음.
		boardChange();
		answer++;
	}

	cout << answer << '\n';

	return 0;
}
