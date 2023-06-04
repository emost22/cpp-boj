#include <iostream>
#define MAX 100001
#define MOD 987654321
using namespace std;
typedef long long ll;

ll dp[MAX][10];
int N;

void init() {
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i < MAX; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = j - 2; k <= j + 2; k++) {
				if (k < 1 || k > 9) continue;

				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
		}
	}
}

void func() {
	ll ret = 0;
	for (int i = 1; i <= 9; i++) {
		ret = (ret + dp[N][i]) % MOD;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}