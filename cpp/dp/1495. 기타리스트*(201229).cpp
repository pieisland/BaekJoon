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
https://m.blog.naver.com/PostView.nhn?blogId=occidere&logNo=221078781781&proxyReferer=https:%2F%2Fwww.google.com%2F
여기를 참고했다.
재귀함수로 푸는 방법은 도저히 이해를 못하겠다.
다음 곡으로 넘어간 걸 왜 보는건지 모르겠어서. 재귀로 이해하는 건 그냥 넘어갔고.
반복문으로 푸는 방법을 숙지했다.

이 분의 글을 보면서 왜 dp로 풀어야 하는지를 이해하게 됐다.
재귀함수의 시간 복잡도는 O(2^N)이 나오기 때문에
현재 N 값이 100까지 가능하므로 2초의 시간제한 내에 답을 구할 수가 없다는 거였다.
그래서 일반적인 dfs로는 풀 수 없는.. 문제.

2중 for문을 돌리는 dp 방식을 사용하면 O(N^2)로 풀 수 있어서 가능한 것 같다.
*/

int n, s, m;
int sound[101];

bool d[101][1001]; //몇번째곡에 대해 해당 볼륨이 가능한지 저장

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//n개의 곡, 스타트 볼륨 s, 볼륨 최댓값 m
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> sound[i];
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 1001; j++) {
			d[i][j] = false;
		}
	}
	
	if (s + sound[0] <= m) d[0][s + sound[0]] = true;
	if (s - sound[0] >= 0) d[0][s - sound[0]] = true;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			// 이전에 j 볼륨이 가능했다면
			// 그 볼륨에 + - 가 가능한 것을 저장.
			if (d[i - 1][j]) {
				if (j + sound[i] <= m) d[i][j + sound[i]] = true;
				if (j - sound[i] >= 0) d[i][j - sound[i]] = true;
			}
		}
	}

	int answer = -1;
	for (int i = m; i >= 0; i--) {
		if (d[n - 1][i]) {
			answer = i;
			break;
		}
	}

	cout << answer << '\n';
	//printDP();

	return 0;
}
