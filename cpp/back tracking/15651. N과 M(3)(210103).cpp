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
n개의 수에서 m개를 고르는데 같은 수를 여러 번 골라도 되며
수열은 사전 순으로 증가하는 순서로 출력.
*/

int n, m;

void dfs2(int cnt, vector<int> num) {
	if (cnt == m) {
		for (int i = 0; i < num.size(); i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';

		return;
	}
	
	for (int i = 1; i <= n; i++) {
		num.push_back(i);
		dfs2(cnt + 1, num);
		num.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

  //맨 처음 시작만 정해주면 된다..?
  //생각해보니 이렇게 할 필요도 없지 않나 싶다.
	//dfs에서 for문 자체가 증가순으로 확인하기 때문에 그냥 하면 됨.
  vector<int> num;
  dfs2(0, num);
  /*for (int i = 1; i <= n; i++) {
		vector<int> num;
		num.push_back(i);
		dfs2(1, num);
		num.pop_back();
	}*/

	return 0;
}
