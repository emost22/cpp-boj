#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> graph[10001], ans;
int dp[10001][2], weight[10001], N;

int Max(int x, int y) {
	return x > y ? x : y;
}

int independent_set(int prev, int v, int turn){
	if (dp[v][turn] != -1) return dp[v][turn];

	int max_weight = 0;

	if (turn) dp[v][turn] = weight[v];
	else dp[v][turn] = 0;

	for (int i = 0; i < graph[v].size(); i++) {
		if (prev == graph[v][i]) continue;
		
		if (turn) {
			dp[v][turn] += independent_set(v, graph[v][i], 0);
		}
		else {
			dp[v][turn] += Max(independent_set(v, graph[v][i], 1), independent_set(v, graph[v][i], 0));
		}
	}

	return dp[v][turn];
}

void find(int prev, int v, int turn) {
	if (turn) {
		ans.push_back(v);
		for (int i = 0; i < graph[v].size(); i++) {
			if (prev == graph[v][i]) continue;

			find(v, graph[v][i], 0);
		}
	}
	else {
		for (int i = 0; i < graph[v].size(); i++) {
			if (prev == graph[v][i]) continue;

			if (dp[graph[v][i]][1] >= dp[graph[v][i]][0]) find(v, graph[v][i], 1);
			else find(v, graph[v][i], 0);
		}
	}
}

void print() {
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int u, v;
	int max_weight = 0, max_index = 0;

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

	int a = independent_set(-1, 1, 1);
	int b = independent_set(-1, 1, 0);
	if (a >= b) {
		cout << a << '\n';
		find(-1, 1, 1);
	}
	else {
		cout << b << '\n';
		find(-1, 1, 0);
	}
	sort(ans.begin(), ans.end());
	print();
	cout << '\n';

	return 0;
}