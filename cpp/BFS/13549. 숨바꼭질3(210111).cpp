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
이 문제는 가중치가 다르기 때문에 단순 bfs 문제가 아니라고 했다.
분류를 보니 0-1 너비우선 탐색 관련해서.. 좀 다른 애인 것 같은데.
그러니까 -1, +1의 순서를 바꾸면 틀림이 나온다.
이유를 알 수가 없음...
*/

int n,k;
int check[100001][2];//0번쨰는 왔던 곳인가고 1은 순간이동을 몇 번 했는가 이다.

void bfs() {
	queue<int> q;

	q.push(n);
	check[n][0] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == k) {
			break;
		}

		int method[3][2] = { {cur * 2, 0}, {cur + 1, 1}, {cur - 1, 1} };

		for (int i = 0; i < 3; i++) {
			int next = method[i][0];
			if (0<=next && next <= 100000 && check[next][0] == 0) {
				check[next][0] = check[cur][0] + 1;
				check[next][1] = check[cur][1];
				if (i == 0) {
					check[next][1] += 1;
				}
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	bfs();

	/*for (int i = 0; i <= k; i++) {
		cout << check[i][0] << ' ' << check[i][1] << endl;
	}*/

	cout << check[k][0] - 1 - check[k][1] << endl;

	return 0;
}
