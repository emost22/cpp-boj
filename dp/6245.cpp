#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 7
using namespace std;

int list[MAX][MAX];
int dp[MAX][MAX];
int direct[2][2] = { {-1,0},{0,1} };
int N;

int transScore(char x) {
	if (x == 'T') return 10;
	if (x == 'J') return 11;
	if (x == 'Q') return 12;
	if (x == 'K') return 13;
	if (x == 'A') return 1;
	return x - '0';
}

bool isOutOfRange(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N;
}

int dfs(int x, int y) {
	if (x == 0 && y == N - 1) return list[x][y];

	int& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;

	for (int d = 0; d < 2; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];

		if (isOutOfRange(nx, ny)) continue;

		ret = max(ret, dfs(nx, ny) + list[x][y]);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(N - 1, 0) << '\n';
}

void input() {
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> str;
			list[i][j] = transScore(str[0]);
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