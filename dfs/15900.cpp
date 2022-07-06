#include <iostream>
#include <vector>
#define MAX 500001
using namespace std;

vector<int> graph[MAX];
bool visit[MAX];
int N, ans;

void dfs(int v, int depth) {
	visit[v] = true;
	bool flag = false;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next]) continue;

		dfs(next, depth + 1);
		flag = true;
	}

	if (!flag) {
		ans += depth;
	}
}

void func() {
	dfs(1, 0);

	if (ans % 2) cout << "Yes\n";
	else cout << "No\n";
}

void input() {
	int u, v;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
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