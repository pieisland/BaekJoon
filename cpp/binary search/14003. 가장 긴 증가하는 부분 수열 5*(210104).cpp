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
참고
https://yabmoons.tistory.com/561

기존 dp로 푸는 문제는 시간 초과가 발생한다.
n값이 너무 크니까. 그래서 이걸 어떻게 해야되냐면 lower bound라는 것을 사용해서 lis 배열을 만들고,
arr[i]에 있는 값이 해당 배열에서 어느 부분에 위치했었는지를 저장하는 indexarr 배열을 사용해서 저장해두어야 한다.
lis 배열의 길이는 lis 길이를 나타내고
제일 뒷 값부터 찾아가면서 저장해둔 후에 출력해주면 되겠다.

lower bound라는 건 원하는 값 k 이상의 값이 처음 나오는 위치를 의미한다.
일반적인 이진탐색과 비교해서 while문의 종료 조건, left, right에 넣는 mid 값이 좀 다른데
lower bound를 찾기 위해서라는 걸 이해하고 가야한다.

while(left < right) 
==이 될 때 멈추게 되고 그 때가 lower bound의 위치이다. 동일하기 때문에 left를 주든가 right를 주든가 상관 없다.
원하는 값 <= lis[mid] 일 때 이하이기 때문에 원하는 위치가 될 수 있고 right = mid 해준다.
반대로 원하는 값 > lis[mid]라면 더 큰 값을 찾아야 하므로 left = mid+1을 해준다.

앞으로 풀 때 헷갈려서 제대로 못 풀 것 같은 느낌이 드는데..
원하는 값 이상이면 right에 mid를 준다는 걸 .. 외우는 것도 하나의 방법이겠다.

사실 lower_bound 라는 걸 사용해서 바로 얻어낼 수 있는 걸로 알고있긴 한데 나는 그냥 while 문이 마음 편할 것 같다.

lower bound, upper bound 설명 
https://m.blog.naver.com/PostView.nhn?blogId=bestmaker0290&logNo=220820005454&proxyReferer=https:%2F%2Fwww.google.com%2F
*/

int n;
int arr[1000000];
int indexarr[1000000];
vector<int> v;//list 배열

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (v.size() == 0 || v[v.size() - 1] < arr[i]) {
			v.push_back(arr[i]);

			//원본의 i번째 있는 데이터는 lis 배열에서 값 번째에 위치.
			indexarr[i] = v.size() - 1;
		}
		else { //증가하는 값이 아니라면 a[i] 값이 증가수열에서 어디에 위치해야할지 저장해준다.
			int left = 0;
			int right = v.size() - 1;
			
      //이게 lower bound를 찾는 부분. left나 right나 어차피 동일한 값이 되어서 마지막에 뭘 하든 상관은 없는 듯 함.
      while (left < right) {
				int mid = (left + right) / 2;
				if (v[mid] >= arr[i]) right = mid;
				else left = mid + 1;//얘는 왜 mid+1임..?
			}
			v[right] = arr[i];//그리고 왜 left에 주는데?
			indexarr[i] = right;
		}
	}

	cout << v.size() << '\n';//정답은 list 배열 자체가 아니지만 길이는 맞다.
	vector<int> ans;

	int idx = v.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (indexarr[i] == idx) {
			ans.push_back(arr[i]);
			idx--;
		}
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}

	return 0;
}
