#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//201022

int dist[1001];
vector<pair<int, int>> bus[1001];
int INF = 987654321;
int n, m;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		for (int i = 0; i < bus[current].size(); i++) {
			int next = bus[current][i].first;
			int nextDistance = distance + bus[current][i].second;

			if (dist[next] > nextDistance) {
				dist[next] = nextDistance;
				pq.push({ -nextDistance, next });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;//도시의 개수
	cin >> m;//버스의 개수

	for (int i = 0; i < m; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		bus[from].push_back({ to, val });
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	int from, to;
	cin >> from >> to;
	dist[from] = 0;

	dijkstra(from);

	cout << dist[to] << '\n';

	return 0;
}
