#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std;

vector<int> list[MAX];
int save[MAX];
bool chk[MAX], visit[MAX][MAX];
int N, M, S, E, K, ans, cnt;

bool dfs(int x) {
	for (int i = 0; i < list[x].size(); i++) {
		int y = list[x][i];
		if (chk[y]) continue;
		chk[y] = true;

		if (save[y] == -1 || dfs(save[y])) {
			save[y] = x;
			return true;
		}
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int testcase, v;
	cin >> testcase;
	while (testcase--) {
		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			cin >> S >> E >> K;
			for (int j = 0; j < K; j++) {
				cin >> v;
				for (int x = S; x < E; x++) {
					if (visit[x][v]) continue;
					list[x].push_back(v);
					visit[x][v] = true;
				}
			}
		}

		fill(save, save + MAX, -1);
		for (int i = 0; i < 100; i++) {
			fill(chk, chk + MAX, false);
			if (dfs(i)) cnt++;
			if (cnt == N) {
				ans = i + 1;
				break;
			}
		}

		if (!ans) ans = -1;

		cout << ans << '\n';
		ans = 0;
		cnt = 0;
		for (int i = 0; i <= 100; i++) list[i].clear();
		memset(visit, false, sizeof(visit));
	}

	return 0;
}