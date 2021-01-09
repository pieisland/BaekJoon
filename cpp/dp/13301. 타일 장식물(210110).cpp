#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

long long fib[90];

void show(int n) {
	for (int i = 0; i <= n; i++) {
		cout << fib[i] << endl;
	}
}

long long fibo(int n) {
	if (n == 0) return 0;
	//if (n == 1 || n == 2) return fib[n] = 1;
	if (fib[n] != 0) return fib[n];
	return fib[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	fib[1] = fib[2] = 1;
	fibo(n);

//	show(n);
//	cout << fib[n] << " " << fib[n - 1] << endl;
	cout << fib[n]*4 + fib[n-1]*2 << '\n';

	return 0;
}
