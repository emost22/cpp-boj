#include <iostream>
#include <cstring>
#define MAX 35
using namespace std;
typedef long long ll;

ll dp[MAX][MAX];
int list[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N;

ll solve(int x, int y) {
	if (x == N - 1 && y == N - 1) return 1LL;

	ll& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;

	for (int d = 0; d < 2; d++) {
		int nx = x + (direct[d][0] * list[x][y]);
		int ny = y + (direct[d][1] * list[x][y]);

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		ret += solve(nx, ny);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
}

void input() {
	cin >> N;
	if (N == -1) exit(0);

	char x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			list[i][j] = x - '0';
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}