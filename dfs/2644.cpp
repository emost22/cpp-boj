#include <iostream>
#include <vector>
using namespace std;

vector<int> list[101];
bool visit[101];
int N, M, start, des, ans;

bool dfs(int v, int cnt) {
	if (v == des) {
		ans = cnt;
		return true;
	}
	visit[v] = true;

	for (int i = 0; i < list[v].size(); i++) {
		int next = list[v][i];

		if (visit[next]) continue;

		bool chk = dfs(next, cnt + 1);
		if (chk) return true;
	}

	return false;
}

void input() {
	int u, v;
	cin >> N >> start >> des >> M;
	while (M--) {
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	if (dfs(start, 0)) cout << ans << '\n';
	else cout << "-1\n";

	return 0;
}