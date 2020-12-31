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
20.12.31

knapsack문제라고 한다. 전형적인 문제인 것이지..

bag이 dp가 되는데, j무게까지 가능한 가방에서 i번째 물건까지 선택이나 미선택을 했을 때의
최대값을 저장하고 있는 것이다.
*/

int n, k;
int bag[101][100001]; //이렇게 크게 해도 되구나....
int weight[101];
int value[101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (weight[i] > j) { //가방 무게보다 더 큰 값이면 이전 물건선택까지 구했던 값을 저장.
				bag[i][j] = bag[i - 1][j];
			}
			else { //들어갈 수 있으면 이전경우에 더하는 것과 안 넣는 것 두 가지 중에 선택.
				bag[i][j] = max(value[i] + bag[i - 1][j - weight[i]], bag[i-1][j]);
			}
		}
	}

	cout << bag[n][k] << '\n';

	return 0;
}
