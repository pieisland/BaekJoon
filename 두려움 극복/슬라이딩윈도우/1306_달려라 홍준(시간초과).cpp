#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int light[1000002];
int lightCnt[1000001];

int findBrightest(int idx) {
	int index = idx - 1;
	while (1) {
		//여기서 문제가 생기진.. 않을 거에요.
		if (lightCnt[index] != 0) return index;
		index--;
	}
}

void show() {
	cout << "개수" << endl;
	for (int i = 1; i <= 5; i++) {
		cout << lightCnt[i] << " ";
	}
	cout << endl;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) { 
		cin >> light[i]; 
	}

	int brightest = 0;
	for (int i = 0; i < 2*m - 1; i++) {
		int val = light[i];
		lightCnt[light[i]] += 1;

		if (val > brightest)
			brightest = val;
	}

	cout << brightest << ' ';

	int e = 0, f = 2 * m-1;
	while (f < n) {
		int l1 = light[e];
		int l2 = light[f];
		//cout << "l1, l2: " << l1 << " " << l2 << endl;
		lightCnt[l1] -= 1;
		lightCnt[l2] += 1;

		//show();

		if (l2 > brightest) { 
			brightest = l2; 
		  // cout << "더 큼" << endl;
		}
		else {
			if (lightCnt[brightest] == 0) {
				//cout << "없어져서 변경" << endl;
				brightest = findBrightest(brightest);
			}
		}
		f++, e++;
		cout << brightest << ' ';
	}

	return 0;
}
