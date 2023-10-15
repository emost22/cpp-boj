#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

int dp[MAX][MAX][MAX << 1], list[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N, M, A, B;

int dfs(int x, int y, int cnt) {
	if (x == N && y == M) {
		return cnt == A;
	}

	int& ret = dp[x][y][cnt];
	if (ret != -1) return ret;
	ret = 0;

	for (int d = 0; d < 2; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];
		int ncnt = cnt;

		if (nx > N || ny > M) continue;
		if (list[nx][ny] == -1) continue;
		if (list[nx][ny] == 1) ncnt++;

		ret += dfs(nx, ny, ncnt);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));

	cout << dfs(1, 1, 0) << '\n';
}

void input() {
	int x, y;
	cin >> N >> M >> A >> B;
	for (int i = 0; i < A; i++) {
		cin >> x >> y;
		list[x][y] = 1;
	}

	while (B--) {
		cin >> x >> y;
		list[x][y] = -1;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}