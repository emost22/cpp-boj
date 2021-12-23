#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1000
using namespace std;

int list[MAX][MAX], dp[MAX][MAX][3];
int direct[2][2] = { {0,1},{1,0} };
int N;

int dfs(int x, int y, int t) {
	if (x == N - 1 && y == N - 1) {
		return list[x][y] == t ? 1 : 0;
	}

	int &ret = dp[x][y][t];
	if (ret != -1) return ret;
	ret = list[x][y] == t ? 1 : 0;
	bool flag = ret == 1 ? true : false;

	int next = 0;
	for (int i = 0; i < 2; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx >= N || ny >= N) continue;
		if (flag) next = max(next, dfs(nx, ny, t < 2 ? t + 1 : 0));
		else next = max(next, dfs(nx, ny, t));
	}
	ret += next;

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0, 0) << '\n';
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