#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int N, M, ans;

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		if (c[t]) continue;
		c[t] = true;

		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int u, v;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		a[u].push_back(v);
	}

	for (int i = 1; i <= N; i++) {
		fill(c + 1, c + 1 + N, false);
		if (dfs(i)) ans++;
	}

	cout << ans << '\n';

	return 0;
}