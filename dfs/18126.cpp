#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 5001
using namespace std;
typedef long long ll;
typedef pair<int, ll> pi;

vector<pi> graph[MAX];
bool visit[MAX];
int N;
ll ans;

void dfs(int v, ll sum) {
	ans = max(ans, sum);
	visit[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		ll nextw = graph[v][i].second;

		if (visit[next]) continue;
		dfs(next, sum + nextw);
	}
}

void func() {
	dfs(1, 0);
	cout << ans << '\n';
}

void input() {
	int u, v;
	ll w;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}