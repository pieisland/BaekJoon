#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//20.10.24
/*
배열에 할당된 크기를 넘어서 접근했을 때
전역 배열의 크기가 메모리 제한을 초과할 때
지역 배열의 크기가 스택 크기 제한을 넘어갈 때
0으로 나눌 떄
라이브러리에서 예외를 발생시켰을 때
재귀 호출이 너무 깊어질 때
이미 해제된 메모리를 또 참조할 때
*/
//findMax에서 end를 써야되는데 right를 썻었음.. 

int n, m;
int light[1000001];
vector<int> tree;

int initTree(int start, int end, int node) {
	if (start == end) return tree[node] = light[start];
	int mid = (start + end) / 2;
	return tree[node] = max(initTree(start, mid, node * 2), initTree(mid + 1, end, node * 2 + 1));	
}

int findMax(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return max(findMax(start, mid, node * 2, left, right), findMax(mid + 1, right, node * 2 + 1, left, right));
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	tree.resize(n * 4);
	for (int i = 0; i < n; i++) {
		cin >> light[i];
	}

	initTree(0, n - 1, 1);
	//for (int i = 0; i < n * 4; i++)
	//	cout << tree[i] << endl;

	for (int i = m - 1; i <= n - m + 1 - 1; i++) {
		int left = i - (m - 1);
		int right = i + (m - 1);
		cout << findMax(0, n - 1, 1, left, right)<<' ';
	}

	return 0;
}
