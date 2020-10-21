#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[2001];
bool visit[2001], chk;
int N, M;

void dfs(int v, int cnt) {
	visit[v] = true;
	if (cnt == 5) {
		chk = true;
		return;
	}
	
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next]) continue;

		dfs(next, cnt + 1);
		visit[next] = false;
	}

	return;
}

bool func() {
	for (int i = 0; i < N; i++) {
		dfs(i, 1);
		visit[i] = false;
		if (chk) return true;
	}

	return false;
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

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	if (func()) cout << "1\n";
	else cout << "0\n";

	return 0;
}