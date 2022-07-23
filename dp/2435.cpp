#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int dp[MAX];
int N, M;

void func() {
	int l = 1;
	int r = M;
	int ans = -1e9;
	while (r <= N) {
		ans = max(ans, dp[r] - dp[l - 1]);
		r++;
		l++;
	}

	cout << ans << '\n';
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