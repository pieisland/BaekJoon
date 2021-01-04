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
이 문제는 n 번위가 작아서 이렇게 풀 수 있었고
n 범위가 커지면 아마도...
그..auto it 사용하는 거로 해야할 것이다. lower bound를 사용하는 방법.
하지만 그것은 vec에 들어있는 값이 수열의 값들을 담은 것이 아니기 때문에
그걸로는 구할 수 없을텐데.
그래서 그냥 n 값을 작게 준 것 같기도 하다. n^2으로 풀라고.
*/

int n;
int arr[1000];
int dp[1000];

void showDP() {
	for (int i = 0; i < n; i++) {
		cout << dp[i] << ' ';
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int maxval = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1; //자기자신은 가능
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] > maxval) maxval = dp[i];
	}

	//showDP();
	int val = maxval;
	vector<int> vec;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == val) {
			vec.push_back(arr[i]);
			val--;
		}
		if (val == 0) break;
	}
	
	cout << maxval << '\n';
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[maxval - 1 - i] << ' ';
	}

	return 0;
}
