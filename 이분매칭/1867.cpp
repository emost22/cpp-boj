#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 501
using namespace std;

vector<int> list[MAX];
int col[MAX];
bool chk[MAX];
int N, K, ans;

bool dfs(int x) {
	for (int i = 0; i < list[x].size(); i++) {
		int y = list[x][i];
		if (chk[y]) continue;
		chk[y] = true;

		if (col[y] == 0 || dfs(col[y])) {
			col[y] = x;
			return true;
		}
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int u, v;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> u >> v;
		list[u].push_back(v);
	}

	for (int i = 1; i <= N; i++) {
		fill(chk, chk + MAX, false);
		if (dfs(i)) ans++;
	}

	cout << ans << '\n';

	return 0;
}