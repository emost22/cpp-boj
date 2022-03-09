#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 501
using namespace std;

vector<vector<int> > list;
vector<vector<vector<int> > > dp;
int N, M;

int dfs(int x, int y, int k) {
	if (x >= N) return 0;

	int& ret = dp[x][y][k];
	if (ret != -1) return ret;
	ret = 0;

	if (y >= M - 1) {
		if (x == N - 1) {
			if (y == M - 1) return ret = list[x][y];
			else return 0;
		}

		if (y == M - 1) {
			if (k) return ret = list[x][y] + dfs(x + 2, 0, 0);
			else return ret = max(list[x][y] + dfs(x + 2, 0, 0), dfs(x + 1, 0, 0));
		}

		if (k) return ret = dfs(x + 2, 0, 0);
		else return ret = dfs(x + 1, 0, 0);
	}

	return ret = max(list[x][y] + dfs(x, y + 2, 1), dfs(x, y + 1, k));
}

void func() {
	cout << dfs(0, 0, 0) << '\n';
}

void input() {
	cin >> N >> M;
	list.assign(N + 1, vector<int>(M + 1, 0));
	dp.assign(N + 1, vector<vector<int> >(M + 1, vector<int>(2, -1)));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		if (!N) return 0;

		func();
	}
}