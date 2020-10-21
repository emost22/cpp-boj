#include <iostream>
using namespace std;
typedef long long ll;

ll dp[61][31][31];
int N;

ll func(int d, int o, int h) {
	if (d == N * 2) return dp[d][o][h] = 1;
	if (dp[d][o][h]) return dp[d][o][h];

	if (o) {
		dp[d][o][h] += func(d + 1, o - 1, h + 1);
	}

	if (h) {
		dp[d][o][h] += func(d + 1, o, h - 1);
	}

	return dp[d][o][h];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		if (!N) return 0;

		cout << func(0, N, 0) << '\n';
	}
}