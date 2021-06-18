#include <iostream>
#include <algorithm>
using namespace std;

int list[2001], dp[2001];
int N, ans;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		for (int j = 1; j < i; j++) {
			if (list[i] < list[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << N - ans - 1 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}