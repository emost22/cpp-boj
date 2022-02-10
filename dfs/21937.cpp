#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> list[MAX];
bool visit[MAX];
int N, M, ans;

void dfs(int v, int cnt) {
	visit[v] = true;
	ans++;

	for (int i = 0; i < list[v].size(); i++) {
		if (visit[list[v][i]]) continue;
		dfs(list[v][i], cnt + 1);
	}
}

void func() {
	int s;
	cin >> s;
	dfs(s, 0);
	cout << ans - 1 << '\n';
}

void input() {
	int u, v;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v;
		list[v].push_back(u);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}