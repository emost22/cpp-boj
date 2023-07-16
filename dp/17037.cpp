#include <iostream>
#define MAX 1002
using namespace std;

int dp[MAX][MAX];
int N, K;

void func() {
	int ret = 0;
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			ret += (dp[i][j] == K);
		}
	}

	cout << ret << '\n';
}

void input() {
	int x1, y1, x2, y2;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1++;
		y1++;
		x2++;
		y2++;
		dp[x1][y1]++;
		dp[x2][y2]++;
		dp[x1][y2]--;
		dp[x2][y1]--;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}