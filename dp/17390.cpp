#include <iostream>
#include <algorithm>
#define MAX 300001
using namespace std;

int dp[MAX];
int N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		dp[i] += dp[i - 1];
	}

	int l, r;
	while (M--) {
		cin >> l >> r;
		cout << dp[r] - dp[l - 1] << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
	}
	sort(dp + 1, dp + 1 + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}