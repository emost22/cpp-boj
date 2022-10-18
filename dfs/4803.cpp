#include <iostream>
#include <vector>
#include <cstring>
#define MAX 501
using namespace std;

vector<int> graph[MAX];
bool visit[MAX];
int N, M;

bool dfs(int v, int pre) {
	visit[v] = true;

	for (auto next : graph[v]) {
		if (pre == next) continue;

		if (visit[next]) return false;
		bool flag = dfs(next, v);
		if (!flag) return false;
	}

	return true;
}

void func(int tc) {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		if (dfs(i, -1)) {
			ans++;
		}
	}

	cout << "Case " << tc << ": ";
	if (!ans) {
		cout << "No trees.\n";
	}
	else if (ans == 1) {
		cout << "There is one tree.\n";
	}
	else {
		cout << "A forest of " << ans << " trees.\n";
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
	}
	memset(visit, false, sizeof(visit));
}

void input() {
	int u, v;
	cin >> N >> M;
	init();
	while (M--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int tc = 1; ; tc++) {
		input();
		if (!N) return 0;
		func(tc);
	}
}