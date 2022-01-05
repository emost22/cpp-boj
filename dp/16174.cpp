#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 64
using namespace std;

int dp[MAX][MAX];
int list[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N;

int dfs(int x, int y) {
	if (x == N - 1 && y == N - 1) return 1;

	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 2; i++) {
		int nx = x + direct[i][0] * list[x][y];
		int ny = y + direct[i][1] * list[x][y];

		if (nx >= N || ny >= N) continue;

		ret = max(ret, dfs(nx, ny));
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	int ans = dfs(0, 0);

	if (ans) cout << "HaruHaru\n";
	else cout << "Hing\n";
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}