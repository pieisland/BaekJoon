#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n, m;
vector<int> arr;

long long int slice(int h)
{
	long long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int temp = arr[i] - h;
		if (temp > 0)//남은 게 있어야 됩니다.
			sum += temp;
	}
	return sum;
}

int BSearch(int target, int low, int high) {
	
	int ret;
	//자른 길이가 target보다 크다면, 더 많이 잘린거죠
	while (low <= high) {
		int mid = (low + high) / 2;
		if (slice(mid) >= target)//그러면 높이를 올려서 덜 잘라보자.
		{	
			low = mid + 1;
			ret = mid;
		}
		else
			high = mid - 1;
	}
	//return high;
	return ret;
}

int main(){

	cin >> n >> m;

	int tree;
	for (int i = 0; i < n; i++)
	{
		cin >> tree;
		arr.push_back(tree);
	}

	//나무 높이를 정렬한 후
	sort(arr.begin(), arr.end());
	cout<<BSearch(m, 0, 2000000000)<<'\n';
	
	return 0;
}
