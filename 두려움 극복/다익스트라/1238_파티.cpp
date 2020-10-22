#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x;
int distance_[1001]; //계속 재사용
int reverseDist[1001]; //한 번 저장
int INF = 987654321;
vector<pair<int, int>> town[1001];

void dijkstra(int start, int number) {
	int dist[1001];
	for (int i = 0; i < 1001; i++) dist[i] = INF;
	dist[start] = 0;

	//거리와 노드번호
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int current = pq.top().second;
		int val = -pq.top().first;
		pq.pop();

		for (int i = 0; i < town[current].size(); i++) {
			int next = town[current][i].first;
			int nextDistance = town[current][i].second + val;
			if (dist[next] > nextDistance) {
				dist[next] = nextDistance;
				pq.push({ -nextDistance, next });
			}
		}
	}

	if (number == 0) {
		for (int i = 0; i < 1001; i++) {
			reverseDist[i] = dist[i];
		}
	}
	else { //도착지로 가는 길입니다..
		for (int i = 0; i < 1001; i++) {
			distance_[i] = dist[i];
		}
	}
}

int main(void){

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;

		town[from].push_back({ to, dist });
	}

	//x에서 다른 마을로 가는 가장 가까운 길.
	dijkstra(x, 0);

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		dijkstra(i, 1);
		int mydist = distance_[x] + reverseDist[i];
		answer = answer < mydist ? mydist : answer;
	}

	cout << answer << '\n';

	return 0;
}
