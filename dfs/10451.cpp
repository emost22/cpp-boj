#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

vector<int> list;
int visit[1001];
int N, cnt;

int dfs(int v) {
	visit[v] = 1;

	if (!visit[list[v]]) {
		return dfs(list[v]);
	}
	else return 1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int Testcase, data;
	cin >> Testcase;
	while (Testcase--) {
		cin >> N;

		list.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> data;
			list[i] = data;
		}

		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				cnt += dfs(i);
			}
		}

		cout << cnt << '\n';

		cnt = 0;
		list.clear();
		memset(visit, 0, sizeof(visit));
	}

	return 0;
}