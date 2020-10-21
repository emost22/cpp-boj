#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

pair<int, int> direct[] = { {0,1},{1,0},{0,-1},{-1,0} };
bool visit[60][60];
char map[60][60];
int dp[60][60];
int N, M, ans;

int dfs(int x, int y, int cnt) {
	if (x < 0 || y < 0 || x >= N || y >= M) return 0;
	if (map[x][y] == 'H') return 0;
	if (visit[x][y]) {
		return ans = -1;
	}

	visit[x][y] = true;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nextx = x + (direct[i].first) * (map[x][y] - 48);
		int nexty = y + (direct[i].second) * (map[x][y] - 48);

		dp[x][y] = max(dp[x][y], dfs(nextx, nexty, cnt + 1) + 1);
		if (ans == -1) return ans;
		visit[nextx][nexty] = false;
	}

	return dp[x][y];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0, 1) << '\n';

	return 0;
}