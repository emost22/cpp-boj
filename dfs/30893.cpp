#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
bool visit[MAX];
int N, S, E, ret;

bool dfs(int v, int t) {
	if (v == E) return true;
	visit[v] = true;

	int cnt = 0;
	bool flag = false;
	for (auto next : graph[v]) {
		if (visit[next]) continue;
		flag |= dfs(next, 1 - t);
		cnt++;
	}
	if (t && cnt > 1) return false;

	return flag;
}

void func() {
	if (dfs(S, 0)) cout << "First\n";
	else cout << "Second\n";
}

void input() {
	int u, v;
	cin >> N >> S >> E;
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
	func();

	return 0;
}