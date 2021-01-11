#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int num[9];
int sel[9];

void dfs(int start, int cnt, int sum) {
	if (cnt == 7) {
		if (sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (sel[i]) cout << num[i] << '\n';
			}
		}

		return;
	}
	if (start >= 9) {
		return;
	}

	for (int i = start; i < 9; i++) {
		sel[i] = 1;
		dfs(i + 1, cnt + 1, sum + num[i]);
		sel[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++) {
		cin >> num[i];
	}

	dfs(0, 0, 0);

	return 0;
}
