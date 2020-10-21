#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[1000001];
bool visit[1000001];
int dp[1000001][2];
int N;

pair<int, int> sol(int v) {
	visit[v] = true;

	dp[v][1] = 1;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next]) continue;

		pair<int, int> p = sol(next);
		dp[v][1] += min(p.first, p.second);
		dp[v][0] += p.second;
	}

	return {dp[v][0], dp[v][1]};
}

void input() {
	int u, v;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	pair<int, int> ans = sol(1);
	
	cout << min(ans.first, ans.second) << '\n';

	return 0;
}