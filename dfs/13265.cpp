#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;

vector<int> graph[MAX];
int visit[MAX];
int N, M;

bool dfs(int v, int k) {
	visit[v] = k;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next]) {
			if (visit[next] == k) return false;
			continue;
		}

		bool flag = dfs(next, 3 - k);
		if (!flag) return false;
	}

	return true;
}

void func() {
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;

		if (!dfs(i, 1)) {
			cout << "impossible\n";
			return;
		}
	}

	cout << "possible\n";
}

void input() {
	int u, v;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
	}
	memset(visit, 0, sizeof(visit));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		init();
	}

	return 0;
}