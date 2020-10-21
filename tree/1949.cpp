#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[10001];
int dp[10001][2], weight[10001], N;

int Max(int x, int y) {
	return x > y ? x : y;
}

int pick(int prev, int v, int turn) {
	if (dp[v][turn] != -1) return dp[v][turn];
	if (turn) dp[v][turn] = weight[v];
	else dp[v][turn] = 0;

	for (int i = 0; i < graph[v].size(); i++) {
		if (prev == graph[v][i]) continue;
		
		if (turn) dp[v][turn] += pick(v, graph[v][i], 0);
		else dp[v][turn] += Max(pick(v, graph[v][i], 1), pick(v, graph[v][i], 0));
	}

	return dp[v][turn];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int u, v;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
	}
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(dp, -1, sizeof(dp));

	int a = pick(-1, 1, 1);
	int b = pick(-1, 1, 0);
	
	cout << Max(a, b) << '\n';

	return 0;
}