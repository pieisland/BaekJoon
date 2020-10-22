#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e;
int connect[401][401];
int d[401][401];
int inf = 987654321;

//201022
//플로이드 와샬
//모든 정점에서 모든 정점으로의 최단 경로를 구하고 싶을 때.
//거쳐가는 정점을 기준으로 최단 거리를 구하자.

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e;

	//맨처음은 inf 값을 넣어둔다.
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			d[i][j] = inf;
		}
	}

	//값을 받고 d에도 저장.
	for (int i = 0; i < e; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		connect[from][to] = dist;
		d[from][to] = dist;
	}

	//최소값 갱신.
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
	
	int min = inf;
	//가장 짧은 사이클을 구한다.
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (d[i][j] + d[j][i] < min)
				min = d[i][j] + d[j][i];
		}
	}
	if (min == inf) cout << -1 << '\n';
	else cout << min << '\n';

	return 0;
}
