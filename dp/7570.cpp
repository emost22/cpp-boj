#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int N, ans;

void input() {
	int x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		dp[x] = dp[x - 1] + 1;
		ans = max(ans, dp[x]);
	}

	cout << N - ans << '\n';
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}