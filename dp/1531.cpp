#include <iostream>
#define MAX 102
using namespace std;

int dp[MAX][MAX];
int N, M;

void func() {
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	int ret = 0;
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			ret += (dp[i][j] > M);
		}
	}
	cout << ret << '\n';
}

void input() {
	int sx, sy, ex, ey;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> sx >> sy >> ex >> ey;
		dp[sx][sy]++;
		dp[sx][ey + 1]--;
		dp[ex + 1][sy]--;
		dp[ex + 1][ey + 1]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}