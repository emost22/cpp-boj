#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 60
using namespace std;

char list[MAX][MAX];
int dp[MAX][MAX];
int N, M;

void func(int tc) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (list[i][j] == 'W' || list[i][j] == 'R' || list[i][j] == 'T');
		}
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int x = 1; x <= N - i; x++) {
				for (int y = 1; y <= M - j; y++) {
					if (dp[x + i][y + j] - dp[x - 1][y + j] - dp[x + i][y - 1] + dp[x - 1][y - 1]) continue;
					ret = max(ret, (i + 1) * (j + 1));
				}
			}
		}
	}

	cout << "Case #" << tc << ": " << ret << '\n';
	memset(dp, 0, sizeof(dp));
}

void input() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}