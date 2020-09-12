#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int connection[10][10];
int check[10][10];
int ans = 9999;

void bfs(int s, int e) {
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		if (pos == e) {
			//목적지라면..

		}

		for (int i = 0; i < 10; i++) {
			if (connection[pos][i] != 0 && check[pos][i] == 0) {
				//연결이 되어있고 간 길이 아니라면
				q.push(i);
				//check[pos][i] = 
			}
		}
	}

}

void dfs(int now, int end, int cost) {	

	if (now == end) {
		if (cost < ans) ans = cost;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (connection[now][i] != 0 && check[now][i]==0) {
			check[now][i] = 1;
			check[i][now] = 1;
			dfs(i, end, cost + connection[now][i]);
			check[now][i] = 0;
			check[i][now] = 0;
		}
	}
}

void main() {

	//연결관계.
	connection[0][1] = 1;
	connection[1][0] = 1;
	connection[0][2] = 2;
	connection[2][0] = 2;
	connection[1][2] = 7;
	connection[2][1] = 7;
	connection[1][3] = 2;
	connection[3][1] = 2;
	connection[2][3] = 15;
	connection[3][2] = 15;
	connection[3][4] = 5;
	connection[4][3] = 5;

	int s = 3;
	int e = 2;

	//3번에서 2번으로 가는 최적의 길을 찾아라.
  
  //bfs에서 값을 어떻게 저장하는지 모르겠어서 dfs로 풀었는데.... 원래 이런 노드 문제는 bfs로 풀어야 되는 거 아니야?
	//bfs(3, 2);

	dfs(3, 2, 0);

	cout << ans << endl;

	return;
}
