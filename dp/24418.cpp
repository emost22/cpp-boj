#include <iostream>
#define MAX 16
using namespace std;

int dp[MAX][MAX];
int N;

void init() {
	for (int i = 1; i < MAX; i++) {
		dp[i][0] = dp[0][i] = 1;
	}

	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
}

void func() {
	init();

	cout << dp[N][N] << ' ' << N * N << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}