#include <iostream>
#include <algorithm>
#define MAX 100002
using namespace std;

int list[MAX], evenSum[MAX / 2], oddSum[MAX / 2], dp[MAX];
int N;

void func() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 2) {
			dp[i] = oddSum[i / 2] + list[N] + evenSum[N / 2 - 1] - evenSum[i / 2];
		}
		else {
			dp[i] = oddSum[i / 2] + evenSum[N / 2 - 1] - evenSum[(i - 1) / 2];
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		if (i % 2) {
			oddSum[i / 2 + 1] = oddSum[i / 2] + list[i];
		}
		else {
			evenSum[i / 2] = evenSum[i / 2 - 1] + list[i];
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