#include <iostream>
#include <algorithm>
#define MAX 250001
using namespace std;

int dp[MAX];
int N, M;

void func() {
	int ans = 0;
	int cnt = 0;
	for (int i = 1; i <= N - M + 1; i++) {
		int sum = dp[i + M - 1] - dp[i - 1];
		if (ans < sum) {
			ans = sum;
			cnt = 1;
		}
		else if (ans == sum) cnt++;
	}

	if (!ans) cout << "SAD\n";
	else cout << ans << '\n' << cnt << '\n';
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