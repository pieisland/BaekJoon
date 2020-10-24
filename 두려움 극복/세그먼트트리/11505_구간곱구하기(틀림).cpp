#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//20.10.24.. 왜 틀렸는지.. 모름.

int n, m, k;
long long arr[1000001];
vector<long long> tree;

#define MOD 1000000007

long long initTree(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = ((initTree(start, mid, node * 2)%MOD)*(initTree(mid + 1, end, node * 2 + 1)%MOD))%MOD;
}

//update가 어렵네...
long long updateTree(int start, int end, int node, int idx, int diff) {
	if (idx<start || idx>end) return tree[node];
	
	//0에 대한 문제가 생기네...
	//if (arr[idx] != 0)	tree[node] = (tree[node] / arr[idx]) * diff;
	//else tree[node] = diff;//말도안되는소리임..
	
	if (start == end) return tree[node] = diff;
	int mid = (start + end) / 2;
	return tree[node] = updateTree(start, mid, node * 2, idx, diff) *updateTree(mid+1, end, node * 2 + 1, idx, diff)%MOD;
}

long long findMultiple(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return findMultiple(start, mid, node * 2, left, right) * findMultiple(mid + 1, end, node * 2 + 1, left, right);
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	tree.resize(n * 4);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	initTree(0, n - 1, 1);

	for (int i = 0; i < m+k; i++) {	
		int a, b, c;
		cin >> a >> b >> c;
		
		if (a == 1) {
			updateTree(0, n - 1, 1, b - 1, c);
		}
		else {
			//b부터 c까지 곱.
			//b보다 c가 큰 게 제대로 돼있는지는 모르겠네요.
			long long answer = findMultiple(0, n - 1, 1, b - 1, c - 1) % MOD;
			cout <<answer << '\n';
		}
	}

	return 0;
}
