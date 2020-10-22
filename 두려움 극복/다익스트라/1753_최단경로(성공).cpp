#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e, k;
int INF = 987654321;

vector<pair<int, int>> vec[20001];
int d[20001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e;
	cin >> k;

	for (int i = 1; i <= v; i++) {
		d[i] = INF;
	}

	//간선을 받는다.
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b, c });
	}

	d[k] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, k });

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

    //이건 동일한 값이라서 안쓰는 것 같음.
		//if (d[current] < distance) continue;
		for (int i = 0; i < vec[current].size(); i++) {
			int next = vec[current][i].first;
			int nextDistance = distance + vec[current][i].second;

			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push({ -nextDistance, next });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF" << endl;
		else cout << d[i] << endl;
	}

	return 0;
}
