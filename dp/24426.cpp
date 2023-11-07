#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];
int list[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N, midX, midY;

int solve(int x, int y, int mx, int my, int ex, int ey) {
	if (x == ex && y == ey) return list[x][y];

	int& ret = dp[x][y];
	if (ret != -1) return ret;

	for (int d = 0; d < 2; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];

		if (nx > ex || ny > ey) continue;
		if (nx == mx && ny == my) continue;

		ret = max(ret, solve(nx, ny, mx, my, ex, ey));
	}
	if (ret >= 0) ret += list[x][y];

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	int ret1 = solve(1, 1, -1, -1, midX, midY) + solve(midX, midY, -1, -1, N, N) - list[midX][midY];
	memset(dp, -1, sizeof(dp));
	int ret2 = solve(1, 1, midX, midY, N, N);

	cout << ret1 << ' ' << ret2 << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> list[i][j];
		}
	}
	cin >> midX >> midY;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}