#include <iostream>
#define MAX 1001
using namespace std;
typedef long long ll;

ll dp[MAX][MAX];
int N, M, K;

void func() {
	ll x1, y1, x2, y2;
	while (K--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << (dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]) / ((x2 - x1 + 1) * (y2 - y1 + 1)) << '\n';
	}
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> dp[i][j];

			dp[i][j] += (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]);
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