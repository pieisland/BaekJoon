#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

/*
19.06.05.수.
와. 자료형에서 난리나네.
90까지라는 게 힌트였다.
int 형 자료 값을 초과하여 이상한 수가 나와
long long int로 해주어야 한다.
*/

long long int arr[90];

int main()
{	
	int n;
	cin >> n;
	arr[0] = 1; //1
	arr[1] = 1; //10

	for (int i = 2; i < n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n - 1];

	return 0;
}
