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
열심히.. 생각해보면 되는 문제인데.
될 것 같으면서도 귀찮은 느낌이 물씬 나는 문제.

일단 가능하다 아니다를 판단할 때
지금 내 숫자와 다음에 나타나는 숫자를 비교해서
나보다 크면은 넘어가고(새로 넣으면 됨)
나보다 작은데 그전까지 찾은 숫자보다 크다면 순서가 안 맞은 거라서
possible을 false로 바꾸고 끝낸다.

출력을 할 때는 
실제로 vector에 넘으면서 했다.
비어있거나 마지막에 있는 수보다 크다면 그 수가 될 때까지
넣어주고
마지막에 빼준다.
*/

int arr[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bool possible = true;
	for (int i = 0; i < n; i++) {
		int next = arr[i];
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				break;
			}
			if (next < arr[j]) {
				possible = false;
			}
			next = arr[j];
		}
		if (!possible) break;
	}

	if (!possible) {
		cout << "NO" << '\n';
	}
	else {
		vector<int> tmp;
		int num = 1;
		for (int i = 0; i < n; i++) {
			int value = arr[i];
			int lastidx = tmp.size() - 1;
			if (tmp.size() == 0 || tmp[lastidx] < arr[i]) {
				while (num <= value) {
					tmp.push_back(num);
					num++;
					cout << '+' << '\n';
				}
			}
			lastidx = tmp.size() - 1;
			if (tmp[lastidx] == value) {
				tmp.pop_back();
				cout << '-' << '\n';
			}
		}
	}

	return 0;
}
