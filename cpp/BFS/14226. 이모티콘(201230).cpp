#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int s;
int visited[1001][1001];
int answer = 987654321;

/*
여러 경우로 가면서 최단으로 가는 걸 구하는 건 역시 bfs...
map 같은 문제 말고 이런것도 bfs로 구한다는 건
이전에 문제 풀면서 습득을 하긴 했었다.

이 문제에서 처음에 헤맸던 부분은
visited 배열에서 나는 맨 처음에 개수만 가지고 있도록 했었는데
복사가 된 것의 개수까지 가지고 있어야 하는 것이었다.

몇 개가 복사가 된 것인지에 대한 정보를 가지고 있지 않으면
복사를 하는데 한 번이 더 증가가 되는데 이모티콘 값은 변하지 않기 때문에
이미 확인한 값이 되어서 저장이 안되기 때문이다.

이전에 했던 방법은
1. 복사하고 바로 붙여넣기
2. 복사했던 거 붙여넣기
3. 삭제하기

이렇게 세 개로 했었는데, visited 배열을 이차원 배열로 바꾸면서
원래 문제에서 말한대로
1. 복사
2. 붙여넣기.
3. 삭제하기
로 구현할 수 있었다.

처음에 찾은 경우가 최소가 되기 때문에
while 문에서 s 개수를 맨 처음으로 찾았을 때가 정답이 되어 break 하면 된다.
*/

void bfs(int cnt, int copy) {
	queue<pair<int, int>> q;
	q.push({ cnt, copy });
	visited[cnt][copy] = 1;

	while (!q.empty()) {
		int nowCnt = q.front().first;
		int nowCopy = q.front().second;
		q.pop();

		if (nowCnt == s) {
			if (visited[nowCnt][nowCopy] - 1 < answer) {
				answer = visited[nowCnt][nowCopy] - 1;
				break;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				//화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
				int newCnt = nowCnt;
				int newCopy = nowCnt;
				if (visited[newCnt][newCopy] == 0) {
					visited[newCnt][newCopy] = visited[nowCnt][nowCopy] + 1;
					q.push({ newCnt, newCopy });
				}
			}
			else if (i == 1) {
				//클림보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
				int newCnt = nowCnt + nowCopy;
				int newCopy = nowCopy;
				if (newCnt <=1000 && visited[newCnt][newCopy] == 0) {
					visited[newCnt][newCopy] = visited[nowCnt][nowCopy] + 1;
					q.push({ newCnt, newCopy });
				}
			}
			else {
				//화면에 있는 이모티콘 중 하나를 삭제한다.
				int newCnt = nowCnt - 1;
				int newCopy = nowCopy;
				if (newCnt>0 && visited[newCnt][newCopy] == 0) {
					visited[newCnt][newCopy] = visited[nowCnt][nowCopy] + 1;
					q.push({ newCnt, newCopy });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	bfs(1, 0);

	cout << answer << '\n';

	return 0;
}
