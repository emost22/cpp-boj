#include <iostream>
using namespace std;

int dp[100001];

int Max(int x, int y) {
	return x > y ? x : y;
}

void find() {
	dp[1] = 1;
	for (int i = 2; i <= 100000; i++) {
		if (i % 2 == 0) {
			dp[i] = Max(i, dp[i / 2]);
		}
		else {
			int n = i;
			int ans = 0;
			while (1) {
				if (n % 2) {
					n = n * 3 + 1;
					ans = Max(ans, n);
				}
				else {
					if (n <= 100000 && dp[n / 2]) {
						dp[i] = Max(ans, dp[n / 2]);
						break;
					}
					n = n / 2;
					if (n == 1) {
						dp[i] = ans;
						break;
					}
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int Testcase, x;
	cin >> Testcase;

	find();
	while (Testcase--) {
		cin >> x;
		cout << dp[x] << '\n';
	}

	return 0;
}