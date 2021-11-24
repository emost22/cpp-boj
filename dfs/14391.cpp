#include <iostream>
#include <algorithm>
#define MAX 4
using namespace std;

char list[MAX][MAX];
bool visit[MAX][MAX];
int N, M, ans;

void solve() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) {
				sum = sum * 10 + list[i][j] - '0';
			}
			else {
				ret += sum;
				sum = 0;
			}
		}
		ret += sum;
	}

	for (int j = 0; j < M; j++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (!visit[i][j]) {
				sum = sum * 10 + list[i][j] - '0';
			}
			else {
				ret += sum;
				sum = 0;
			}
		}
		ret += sum;
	}

	ans = max(ans, ret);
}

void dfs(int v) {
	if (v == N * M) {
		solve();
		return;
	}

	int x = v / M;
	int y = v % M;
	visit[x][y] = true;
	dfs(v + 1);

	visit[x][y] = false;
	dfs(v + 1);
}

void func() {
	dfs(0);
	cout << ans << '\n';
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