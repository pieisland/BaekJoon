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
20.12.30
회전했을 때 방향 정보를 저장해놓는 게 중요한 것 같다.
이렇게 하나하나 안해도 될 것 같기는 한데.. 이것밖에 생각이 안 남.

ny, nx를 갱신해줘야 했고
min과 max 값에 대해서 구했을 때 바로바로 계산해도 되는 문제였다.

넓이를 구하는 건 max - min 해서 구하면 된다.
*/

int dir[4][2][2] = {
	{{-1, 0}, {1, 0}}, //기본
	{{0, 1}, {0, -1}}, //오른쪽회전
	{{1, 0}, {-1, 0}}, //으로 갈때마다
	{{0,-1}, {0, 1} } //증가하면 됩니다.
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int cy = 0;
		int cx = 0;
		int d = 0;

		int miny = 0, minx = 0, maxy = 0, maxx = 0;

		for (int i = 0; i < s.length(); i++) {
			int ny, nx;
			switch (s[i]) {
			case 'F':
				ny = cy + dir[d][0][0];
				nx = cx + dir[d][0][1];
				break;
			case 'B':
				ny = cy + dir[d][1][0];
				nx = cx + dir[d][1][1];
				break;
			case 'R':
				d += 1;
				if (d == 4) d = 0;
				ny = cy;
				nx = cx;
				break;
			case 'L':
				d -= 1;
				if (d < 0) d = 3;
				ny = cy;
				nx = cx;
				break;
			default:
				break;
			}

			if (ny < miny) miny = ny;
			if (nx < minx) minx = nx;
			if (ny > maxy) maxy = ny;
			if (nx > maxx) maxx = nx;
			cy = ny;
			cx = nx;
		}

		int size = (maxy - miny ) * (maxx - minx);
		cout << size << '\n';

	}
	
	return 0;
}
