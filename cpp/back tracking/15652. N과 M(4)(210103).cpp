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
1부터 n까지 자연수 중 m개를 고르는데
같은 수를 여러 개 골라도 되며
 수열은 비내림차순이다. 즉 == 가능하다.
*/

int n, m; //n개의 수 중 m개를 고르기

//start가 있어서 어디서부터 시작할 지 정할 수 있다.
void dfs(int start, int cnt, vector<int> num) {
	if (cnt == m) {
		for (int i = 0; i < num.size(); i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (start > n) return;

  //다시 dfs를 호출할 때 i를 보내기 때문에 == 할 수 있다.
	for (int i = start; i <= n; i++) {
		num.push_back(i);
		dfs(i, cnt + 1, num);
		num.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<int> num;
	dfs(1, 0, num);

	return 0;
}
