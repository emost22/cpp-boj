#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 5001
using namespace std;

vector<int> graph[MAX];
int list[MAX], dp[MAX];
int N, M;

int dfs(int x) {
	int &ret = dp[x];
	if (ret != -1) return ret;
	ret = 1;

	for (int i = 0; i < graph[x].size(); i++) {
		int next = graph[x][i];

		if (list[x] >= list[next]) continue;
		ret = max(ret, dfs(next) + 1);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		cout << dfs(i) << '\n';
	}
}

void input() {
	int u, v;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	while (M--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}