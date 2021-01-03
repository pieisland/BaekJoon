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
n개의 수에서 m개의 수를 고르는데
중복 없이 오름차순으로.
*/

int n, m;

void dfs(int start, int cnt, vector<int> num) {
	if (cnt == m) {
		for (int i = 0; i < num.size(); i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (start > n) return;

	for (int i = start; i <= n; i++) {
		num.push_back(i);
		dfs(i+1, cnt + 1, num);
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
