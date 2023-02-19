#include <iostream>
#define MAX 201
#define MOD 1000000007
using namespace std;

char list[MAX][MAX];
int dp[MAX][MAX];
int N, M;

bool isPossible(int x, int y) {
	return x > 0 && y > 0 && x <= N && y <= M && list[x][y] == '.';
}

void func() {
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (list[i][j] == 'X') continue;

			if (isPossible(i, j + 1)) {
				dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
			}

			if (isPossible(i + 1, j)) {
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
			}
		}
	}

	cout << dp[N][M] << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
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