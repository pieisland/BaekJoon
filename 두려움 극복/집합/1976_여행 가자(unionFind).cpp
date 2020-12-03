#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cities[201][201]; //도시의 연결관계 저장.
int parent[201];

//최상위 부모를 찾아 return.
int findParent(int n) {
	if (parent[n] == n) return n;
	return parent[n] = findParent(parent[n]);
}

//부모 연결..
void unionSet(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	//크기를 비교하지 않는 이유는
	//for문에서 이미 부모가 작은 값부터 확인해서 설정했기 때문이 아닐까 싶다.
	parent[b] = a;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cities[i][j];
			if (cities[i][j] == 1) {
				//연결이 돼있다면 union해준다.
				if(findParent(i) != findParent(j))
					unionSet(i, j);
			}
		}
	}

	int firstCity;
	cin >> firstCity;
	firstCity = findParent(firstCity);
	
	//나머지 여행지가 첫 여행지와 같은 부모를 가지면 같은 집합에 속한 거라 갈 수 있는 길이 있다.
	string answer = "YES";
	for (int i = 1; i < m; i++) {
		int x;
		cin >> x;
		if (findParent(x) != firstCity) {
			answer = "NO";
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}
