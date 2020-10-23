#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//20.10.2
//기본 greedy 문제. 거스름돈이랑 같은 듯.

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	int cnt[3] = { 0, 0, 0 };
	cin >> t;
	if (t % 10 != 0) {
		cout << -1 << '\n';
	}
	else {
		//5분은 300초, 1분은 60초, 10초
		int tmp = t;
		cnt[0] = tmp / 300;
		tmp = tmp % 300;
		cnt[1] = tmp / 60;
		tmp = tmp % 60;
		cnt[2] = tmp / 10;

		cout << cnt[0] << " " << cnt[1] << " " << cnt[2];
	}

	return 0;
}
