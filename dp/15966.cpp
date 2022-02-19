#include <iostream>
#include <algorithm>
#define MAX_N 100001
#define MAX_A 1000001
using namespace std;

int list[MAX_N], dp[MAX_A];
int N;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		dp[list[i]] = max(dp[list[i]], dp[list[i] - 1] + 1);
		ans = max(ans, dp[list[i]]);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}