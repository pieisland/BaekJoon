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
제일 큰 수를 구해두고 한 번만 dp 해서
원하는 값들을 출력하면 된다.

dp[0]이 0인 숫자를 만드는 방법..인데. 1로 해야 
dp[1]에서 0에 1을 더하는 방법이 한 가지 있으니까 1이 될 수 있다.

.. 말이 좀 이상하긴 한데. 아무튼 전형적인 문제였고.
%를 하는 위치가 문제가 되기도 한다.
*/

int dp[1000001];
vector<int> testnum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n;
	cin >> t;

	int maxval=0;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		if (maxval < num) maxval = num;
		testnum.push_back(num);
	}
	
  dp[0] = 1;
  for (int i = 1; i <= maxval; i++) {
    for (int j = 1; j <= 3; j++) {
      if (i - j >= 0) {
        dp[i] = (dp[i] + dp[i - j])% 1000000009;
      }
    }
  }

	for (int i = 0; i < testnum.size(); i++) {
		cout << dp[testnum[i]] << '\n';
	}
  
	return 0;
}
