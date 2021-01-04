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
이 문제는 책을 보고 풀었다.
인덱스가 너무 헷갈리는 부부인 것 같다.
이전 값을 비교하기 위해 -1을 쓰기 때문에
lcs는 1부터 시작하지만
string 값은 0부터 시작하니까 -1 뺴주면서 하는 식.
lcs 마지막 값이 lcs의 길이가 되고

출력을 하기 위해서는 lcs에 저장된 값을 탐색하면서
인덱스 값 바꾸면서 확인해나간다.

이런 비슷한 문제가.. 어디 더 있을텐데.
*/

string s1, s2;
int lcs[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s1;
	cin >> s2;

	int n = s1.length();
	int m = s2.length();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//인덱스가 서로 달라서 헷갈리지요....
			if (s1[i - 1] == s2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	int lcslen = lcs[n][m];

	cout << lcslen << '\n';

	int i = n, j = m;
	int len = lcslen;
	vector<char> ans;

	//lcs 배열은 이동 방향을 정해줄 뿐
	//확인 하는 건 문자열에서 확인하면 됩니다.
	while (i > 0 && j > 0) {
		if (s1[i-1]==s2[j-1]) {
			//cout << s1[i - 1];
			ans.push_back(s1[i - 1]);//둘 중 뭘 넣어도 상관 없지.
			i -= 1;
			j -= 1;
			len -= 1;
		}
		else {
			//더 큰 부분으로 이동..
			if (lcs[i - 1][j] > lcs[i][j - 1])
				i -= 1;
			else
				j -= 1;
		}
	}

	//반대로 출력해주면 된다.
	for (int i = 0; i < lcslen; i++) {
		cout << ans[lcslen - 1 - i];
	}
	cout << endl;

	return 0;
}
