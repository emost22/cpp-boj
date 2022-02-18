#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 301
using namespace std;

int dp[MAX][MAX];
int list[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N, M;

int dfs(int x, int y) {
	if (x == N - 1 && y == M - 1) return 0;
	
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 1e9;

	int dis = list[x][y];
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= dis; j++) {
			int nx = x + direct[i][0] * j;
			int ny = y + direct[i][1] * j;

			if (nx >= N || ny >= M) break;
			ret = min(ret, dfs(nx, ny) + 1);
		}
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
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