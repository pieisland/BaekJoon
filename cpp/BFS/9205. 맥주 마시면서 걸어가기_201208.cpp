#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

//20.12.08.화
//이전에 풀었던 문제를 dfs -> bfs로 풀어봤다.
//사실 먼저 정보에 대한 저장을 해놓은 상태이기 때문에 쉽게 풀었던 것..
//이 문제에서는 다음으로 갈 수 있는 곳에 대한 정보를 미리 걸러서 저장을 한다는 점이
//익숙하지 않았고.. for문에서도 i+1부터 n까지 이렇게 하는것도.. 뭔가 바로 생각나기는
//어려울 것 같다는 생각이 들었다.

int n;
int arr[102];//a정점에서 갈 수 있는 경로들 모두 확인 했는지 저장.
vector<int> vec[102]; //한 정점에서 다른 정점으로 갈 수 있는 점들을 저장.
vector<pair<int, int>> pos; // 모든 점들의 위치값을 저장.

int bfs(int num) {
	queue<int> q;
	q.push(num);
	arr[num] = 1;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == n - 1) {
			return 1;
		}
		
		for (int i = 0; i < vec[current].size(); i++) {
			int next = vec[current][i];

			if (arr[next] == 0) {
				arr[next] = 1;
				q.push(next);
			}
		}
	}

	return 0;
}

int main() {

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		n += 2;

		int a, b;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			pos.push_back(pair<int, int>(a, b));
		}

		//이렇게 해야 중복 없이 저장 가능.
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				int x = pos[i].first - pos[j].first;
				if (x < 0)x = -x;
				int y = pos[i].second - pos[j].second;
				if (y < 0)y = -y;

				//20병의 맥주를 모두 마셔도 상관없는 거리는 1000까지.
				if (x + y <= 1000) {
					//양방향 그래프니까 같이 저장해주기.
					vec[i].push_back(j);
					vec[j].push_back(i);
				}
			}

		int check = bfs(0);

		//시작 위치에서 페스티벌까지 맥주 안 떨어지고 갈 수 있으면,
		//맥주가 다 떨어지면 값이 102를 바로 넣기 떄문에.
		if (check == 1)
			cout << "happy" << endl;
		else
			cout << "sad" << endl;

		pos.clear();

		//이런 형태의 벡터는 하나하나마다 클리어를 해줘야되구나.
		for (int i = 0; i < 102; i++)
			vec[i].clear();
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}
