#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cities[201][201]; //도시의 연결관계 저장.
int check[201][201]; //갔던 곳인지 아닌지 확인.
vector<int> routes;

//from에서 to로 갈 수 있으면 true, 없으면 false 반환.
bool checkTravelPossible(int from, int to) {
	queue<int> q;
	q.push(from);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == to) return true;

		//now와 연결된 도시에 대해서 가지 않았으면 큐에 추가.
		for (int i = 1; i <= n; i++) {
			if (cities[now][i] == 1 && check[now][i] == 0) {
				check[now][i] = 1;
				check[i][now] = 1;
				q.push(i);
			}
		}
	}

	return false;
}

//갔던 정보를 초기화.
void clearCheck() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			check[i][j] = 0;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cities[i][j];
		}
	}

	//여행 순서를 받는다.
	for (int i = 0; i < m; i++) {
		int city;
		cin >> city;
		routes.push_back(city);
	}

	string answer="YES";
	for (int i = 0; i < m - 1; i++) {
		int from = routes[i];
		int to = routes[i + 1];
		//한 번이라도 불가능하면 no.
		if (!checkTravelPossible(from, to)) {
			answer = "NO";
			break;
		};
		clearCheck();
	}

	cout << answer << '\n';

	return 0;
}
