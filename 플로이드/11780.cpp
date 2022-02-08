#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

vector<int> ans;
int d[MAX][MAX], path[MAX][MAX];
int N, M;

void solve(int u, int v) {
	if (!path[u][v]) {
		ans.push_back(u);
		ans.push_back(v);
		return;
	}

	solve(u, path[u][v]);
	ans.pop_back();
	solve(path[u][v], v);
}

void func() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					path[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (d[i][j] == 1e9) cout << "0 ";
			else cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j || d[i][j] == 1e9) {
				cout << "0\n";
				continue;
			}

			solve(i, j);
			cout << ans.size() << ' ';
			for (int k = 0; k < ans.size(); k++) {
				cout << ans[k] << ' ';
			}
			cout << '\n';
			ans.clear();
		}
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			d[i][j] = 1e9;
		}
	}
}

void input() {
	int u, v, w;
	cin >> N >> M;
	init();
	while (M--) {
		cin >> u >> v >> w;
		d[u][v] = min(d[u][v], w);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}