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
회전의 경우의 수를 구하고 그만큼 회전을 시키고
그에 따라 행 값을 계산하고. 이런식으로 해야될텐데.
회전을 하는 것 자체도 어려움..(go 함수가 어렵긴 했어요)

회전을 하면서 기존 값이 이제 덮어씌워지기 때문에
덮어씌워지는 값을 미리 저장을 해둬야한다.
그래서 일단, nextVal에 초반에는 이전 위치에 있는 값을 저장해서 그거를 덮어준 후에
tmp로 저장해둔 거를 다시 저장해줬다.
이 부분이 매우 헷갈렸다.
tmp에 새로운 다음 값을 임시로 저장을 해둔다.
nextVal에 저장한 이전의 다음 값을 옮겨준다.
nextVal을 갱신해준다.

회전을 하는 타이밍에서도 헷갈렸다.
count 값을 1로 시작해야하나 0으로 시작해야하나 했는데
기존은 0이고 다음 위치를 확인할 때마다 1 증가하고
길이만큼 되면 삐져나간 것으로 이해해서 0 초기화해주고 dir를 바꿔줬다.

이건 항상 헷갈릴 것 같은 예감인데.
이거 분명 쉽게 하는 방법이 있지 않았나. 유튜브에서 봤던 것 같은데.

그렇게 바깥쪽 회전을 마치고 나면 안으로 들어가야하는데
y+1, x+1, length-2로 재귀함수를 작성했고
길이가 1이 되거나(초기 정사각형 크기가 홀수였던 경우)
길이가 0이 되면(초기 정사각형 크기가 짝수였던 경우)
return하도록 해줬다.

재귀까지 다 돌고나면 회전이 다 끝난 상태인 것이고
그 후에 행에서 최소 값을 구해줘서 저장한다.
answer를 계속해서 갱신해준다.

재귀까지 있고 dfs도 있지만 k도 작고 해서 시간 안에 풀 수 있었던 문제..
회전에 대한거는 좀 더 정리를 하든가 하는 게 필요할 것 같다.
소용돌이로 회전하는 것도 있는데.. 그거는 아마 check로 갔던 길인지 확인하면서 할 것이다.
*/
int n, m, k;
int arr[51][51]; 
int tmp[51][51];
int check[6];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int answer = 987654321;

typedef struct RotInfo {
	int r, c, s;
};

RotInfo rotInfo[6];

void copyArr() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
}

void printTmp() {
	cout << "print tmp" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << tmp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

//시작 위치랑 길이
void go(int y, int x, int length) {
	if (length == 1 || length == 0) { 
		return; 
	}

	int dirIdx = 0;

	int count = 0;

	int cy = y;
	int cx = x;
	int nextVal = tmp[cy][cx];
	while (1) {
		int ny = cy + dir[dirIdx][0];
		int nx = cx + dir[dirIdx][1];
		count++;
		int tmpVal = tmp[ny][nx];

		if (count == length) {
			//방향을 바꿔야 합니다.
			dirIdx++;
			count = 0;
			continue;
		}

		tmp[ny][nx] = nextVal;
		nextVal = tmpVal;
		cy = ny;
		cx = nx;

		if (cy == y && cx == x) break;
	}

	go(y + 1, x + 1, length - 2);
}

int getMinVal() {
	int ret = 987654321;
	for (int i = 1; i <= n; i++) {
		int sumVal = 0;
		for (int j = 1; j <= m; j++) {
			sumVal += tmp[i][j];
		}
		if (sumVal < ret) {
			ret = sumVal;
		}
	}
	return ret;
}

void rotate(vector<int> vec) {
	copyArr();

	for (int i = 0; i < k; i++) {
		int idx = vec[i];
		int r = rotInfo[idx].r;
		int c = rotInfo[idx].c;
		int s = rotInfo[idx].s;

		//r-s, r+s, / c-s, c+s
		int length = 2 * s + 1;
		int startY = r - s;
		int startX = c - s;

		go(startY, startX, length);
	}

	int val = getMinVal();
	if (val < answer) answer = val;

	//cout << "진짜최종" << endl;
	//printTmp();
}

void dfs(int cnt, vector<int> vec) {
	if (cnt == k) {
		rotate(vec);
		return;
	}

	for (int i = 0; i < k; i++) {
		if (check[i]) continue;
		check[i] = 1;
		vec.push_back(i);
		dfs(cnt + 1, vec);
		check[i] = 0;
		vec.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j]; 
		}
	}

	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		rotInfo[i].r = r;
		rotInfo[i].c = c;
		rotInfo[i].s = s;
	}

	vector<int> vec;
	dfs(0, vec);

	cout << answer << '\n';
  
	return 0;
}
