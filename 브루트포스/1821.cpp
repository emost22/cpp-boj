#include <iostream>
#define MAX 11
using namespace std;

bool visit[MAX];
int dp[MAX][MAX];
int N, E;

void dfs(int cnt) {
	if (cnt == N) {
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N - i; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
			}
		}

		if (dp[N - 1][0] == E) {
			for (int i = 0; i < N; i++) {
				cout << dp[0][i] << ' ';
			}
			cout << '\n';
			exit(0);
		}
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;

		dp[0][cnt] = i;
		visit[i] = true;
		dfs(cnt + 1);
		visit[i] = false;
	}
}

void func() {
	dfs(0);
}

void input() {
	cin >> N >> E;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}