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
이 문제가 fibonacci가 되는 이유는
n개로 만들 때 n-1의 뒤에 1을 붙여주고
n-2의 뒤에 00을 붙여준다고 보면 되기 때문이다.
*/

int n;
int fiboArr[1000000+10];

int fibo(int num) {
	if (num == 0) return 0;
	if (fiboArr[num]) return fiboArr[num];
	return fiboArr[num] = (fibo(num-1) + fibo(num-2))%15746;
}

int main() {

	//scanf("%d", &n);

	cin >> n;

	fiboArr[1] = 1;
	fiboArr[2] = 1;
	fibo(n+1);
	
	/*for (int i = 0; i <= n + 1; i++) {
		cout<<fiboArr[i]<<'\n';
	}*/
	cout << fiboArr[n+1] << '\n';

	return 0;
}
