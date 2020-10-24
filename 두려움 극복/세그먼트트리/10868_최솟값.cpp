#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//완전 똑같은 문제라. 20.10.24
//이걸 먼저 풀고 합쳤으면 됐을 듯.

int n, m;
int light[100001];
vector<int> tree2;

int initTree2(int start, int end, int node) {
	if (start == end) return tree2[node] = light[start];
	int mid = (start + end) / 2;
	return tree2[node] = min(initTree2(start, mid, node * 2), initTree2(mid + 1, end, node * 2 + 1));
}

int findMin(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 9876543210;
	if (left <= start && end <= right) return tree2[node];
	int mid = (start + end) / 2;
	return min(findMin(start, mid, node * 2, left, right), findMin(mid + 1, end, node * 2 + 1, left, right));
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	tree2.resize(n * 4);

	for (int i = 0; i < n; i++) {
		cin >> light[i];
	}

	initTree2(0, n - 1, 1);

	for (int i = 0; i < m; i++) {	
		int left, right;
		cin >> left >> right;
		left -= 1;
		right -= 1;
		cout << findMin(0, n - 1, 1, left, right) << " " << '\n';
	}

	return 0;
}
