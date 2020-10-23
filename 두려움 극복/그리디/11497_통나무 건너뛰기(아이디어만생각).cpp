#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int namoo[10001]; //나무 높이 저장.
int arr[10001]; //나무 정렬.

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> namoo[i];
		}
		//정렬
		sort(namoo, namoo + n);
		
		//수를 채울 대 왼쪽 끝, 오른족 끝, 이런 순으로 채워준다.
		int f = 0;
		int e = n - 1;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				arr[f++] = namoo[i];
			}
			else {
				arr[e--] = namoo[i];
			}
		}
		arr[n] = arr[0];

		int answer = 0;
		for (int i = 0; i < n; i++) {
			int diff = arr[i] - arr[i + 1] > 0 ? arr[i] - arr[i + 1] : arr[i + 1] - arr[i];
			if (diff > answer) answer = diff;
		}
		cout << answer<<'\n';
	}

	return 0;
}
