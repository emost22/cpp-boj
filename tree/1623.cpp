#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> graph[200001], ans;
int dp[200001][2], weight[200001], N;

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
	cout << "-1\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int parent;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
	}
	for (int i = 2; i <= N; i++) {
		cin >> parent;
		graph[parent].push_back(i);
	}
	memset(dp, -1, sizeof(dp));

	int a = pick(-1, 1, 1);
	int b = pick(-1, 1, 0);

	cout << a << ' ' << b << '\n';

	find(-1, 1, 1);
	sort(ans.begin(), ans.end());
	print();

	ans.clear();
	find(-1, 1, 0);
	sort(ans.begin(), ans.end());
	print();

	return 0;
}