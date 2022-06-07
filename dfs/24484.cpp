#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100001
using namespace std;
typedef long long ll;

vector<int> graph[MAX];
ll visit[MAX];
int N, M, S;
ll ans, cnt;

void dfs(int v, ll d) {
	visit[v] = d;

	ans += (d * (++cnt));
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next] != -1) continue;

		dfs(next, d + 1);
	}
}

void func() {
	memset(visit, -1, sizeof(visit));
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), [](int a, int b) {
			return a > b;
		});
	}

	dfs(S, 0);

	cout << ans << '\n';
}

void input() {
	int u, v;
	cin >> N >> M >> S;
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