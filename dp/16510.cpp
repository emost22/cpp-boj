#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int dp[MAX];
int N, M;

void func() {
	int t;
	while (M--) {
		cin >> t;
		cout << upper_bound(dp + 1, dp + 1 + N, t) - dp - 1 << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}