#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n, m; //1000이 최대
int dp[1000+10][1000+10];//i, j에서 시작한 최대 정사각형 크기..
int arr[1000+10][1000+10];
int ans;

/*
dp는 메모이제이션 기법을 써야했는데 그전에 사용하지 않은 점이 일단 문제였음.

또 여러 문제.
arr[y][x] 값이 0일 때는 주변 값들이 더 큰 정사각형을 만들 수 있어도 그 위치에서 만들 수 있는 정사각형은 0이 되는 점.
arr[y][x] 값이 0이라고 바로 return 해버리면 다른 값들을 구할 수가 없다는 점.
dp[y][x]에 0을 넣게 되는 것도 값을 구한 것으로 봐야 하기 때문에 초기 dp 값을 -1이나 다른 값으로 설정해야 했다는 점.

이래저래 조금씩 잘못된 점들을 잡아야 했던 문제.
*/

void printDp() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
}

int recur(int y, int x) {
	if (y >= n || x >= m) return 0;
	//if (arr[y][x] == 0) return 0;

	if (dp[y][x]>=0) {
		return dp[y][x];
	}

	int squareValue = min(recur(y + 1, x), min(recur(y, x + 1), recur(y + 1, x + 1)));

	if (ans < arr[y][x] + squareValue) {
		ans = arr[y][x] + squareValue;
	}
	
	dp[y][x] = arr[y][x] + squareValue;

	if (arr[y][x] == 0) dp[y][x] = 0;

	return dp[y][x];
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}

	recur(0, 0);

	//printDp();

	cout << ans*ans << '\n';

	return 0;
}
