#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>
#define min(a, b) {a < b ? a : b}
using namespace std;
typedef long long ll;

vector<pair<int, int> > list[10001];
bool visit[10001];
int subTree[10001];
int N;
ll sum[10001], ans;

void dfs(int v) {
	visit[v] = true;

	subTree[v] = 1;
	for (int i = 0; i < list[v].size(); i++) {
		int next = list[v][i].first;
		int weight = list[v][i].second;

		if (visit[next]) continue;

		dfs(next);
		subTree[v] += subTree[next];
		sum[v] += (subTree[next] * weight + sum[next]);
	}
}

void solve(int v, ll sum) {
	visit[v] = true;
	ans = min(ans, sum);

	for (int i = 0; i < list[v].size(); i++) {
		int next = list[v][i].first;
		int weight = list[v][i].second;

		if (visit[next]) continue;

		solve(next, sum - (subTree[next] * weight) + ((N - subTree[next]) * weight));
	}
}

void input() {
	int u, v, w;
	for (int i = 1; i < N; i++) {
		cin >> u >> v >> w;
		list[u].push_back({ v,w });
		list[v].push_back({ u,w });
	}
}

void init() {
	ans = LLONG_MAX;
	memset(sum, 0, sizeof(sum));
	memset(subTree, 0, sizeof(subTree));
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < N; i++) list[i].clear();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		if (!N) break;
		init();
		input();
		dfs(0);
		memset(visit, false, sizeof(visit));
		solve(0, sum[0]);
		cout << ans << '\n';
	}

	return 0;
}