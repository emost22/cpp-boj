#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 31
using namespace std;
typedef long long ll;

ll dp[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N, M;

ll dfs(int x, int y) {
	if (x == M && y == M) return 1;

	ll& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 2; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < N || ny < N || nx > M || ny > M) continue;
		if (nx < ny) continue;

		ret += dfs(nx, ny);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(N, N) << '\n';
}

void input() {
	cin >> N >> M;
	if (N > M) swap(N, M);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}