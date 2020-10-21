#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[1000001], list[1000001];
bool visit[1000001];
int dp[1000001][2];
int N;

void dfs(int v) {
	visit[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next]) continue;
		list[v].push_back(next);
		dfs(next);
	}
}

int sol(int v, int t) {
	if (dp[v][t] != -1) return dp[v][t];

	if (t) dp[v][t] = 1;
	else dp[v][t] = 0;

	for (int i = 0; i < list[v].size(); i++) {
		int next = list[v][i];

		if (t) {
			dp[v][t] += min(sol(next, t), sol(next, 1 - t));
		}
		else dp[v][t] += sol(next, 1 - t);
	}

	return dp[v][t];
}

void input() {
	int u, v;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	dfs(1);
	cout << min(sol(1, 1), sol(1, 0)) << '\n';

	return 0;
}