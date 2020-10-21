#include <iostream>
using namespace std;

int v, e, k;
//너무 큰 숫자 아닌가요....?
//이렇게 받으면 안될 것 같은데.
int node[20001][20001];
int d[20001];
const int INF = 987654321;
bool visited[20001] = {false};
//메모리 끝날 것 같은데.

int getSmallIndex() {
	int min = INF;
	int index = 1;
	for (int i = 1; i <= v; i++) {
		if (d[i] < min && !visited[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> v >> e;
	cin >> k;

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++)
			node[i][j] = INF;
	}


	//간선을 받는다.
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a][b] = c;
	}

	for (int i = 1; i <= v; i++) {
		if (i == k) d[i] = 0;
		else d[i] = INF;
	}

	for (int i = 1; i <= v; i++) {
		if(node[k][i]!=0) d[i] = node[k][i];
	}

	visited[k] = true;
	for (int i = 1; i <= v; i++) {
		int current = getSmallIndex();
		visited[current] = true;
		for (int j = 1; j <= v; j++) {
			if (!visited[j]) {
				if (d[current] + node[current][j] < d[j]) {
					d[j] = d[current] + node[current][j];
				}
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF" << endl;
		else cout << d[i] << endl;
	}

	return 0;
}
