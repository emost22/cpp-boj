#include <iostream>
#include <cstring>
using namespace std;

char list[110][110];
int dp[101][101];
int N, M;

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (list[i][j] == '.') {
				if (dp[i][j - 1] != -1) dp[i][j] = dp[i][j - 1] + 1;
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	print();

	return 0;
}