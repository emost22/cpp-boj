#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int dp[MAX][2];
int N;

int dfs(int v, int pre, int flag) {
	int& ret = dp[v][flag];
	if (ret != -1) return ret;
	ret = flag;

	for (auto next : graph[v]) {
		if (pre == next) continue;
		if (flag) {
			ret += min(dfs(next, v, 1), dfs(next, v, 0));
		}
		else {
			ret += dfs(next, v, 1);
		}
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << min(dfs(1, 0, 1), dfs(1, 0, 0)) << '\n';
}

void input() {
	int u, v;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
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