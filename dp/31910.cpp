#include <iostream>
#include <cstring>
#define MAX 31
using namespace std;
typedef long long ll;

int direct[2][2] = { {1,0},{0,1} };
int list[MAX][MAX];
ll dp[MAX][MAX];
int N;

bool isOutOfRange(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N;
}

ll dfs(int x, int y, int b) {
	if (x == N - 1 && y == N - 1) return list[x][y];

	ll& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;

	ll tmp = list[x][y] ? (ll)1 << b : 0;
	for (int d = 0; d < 2; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];

		if (isOutOfRange(nx, ny)) continue;

		ret = max(ret, dfs(nx, ny, b - 1) + tmp);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0, (N << 1) - 2) << '\n';
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