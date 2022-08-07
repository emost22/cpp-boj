#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

ll dp[MAX];
int N, M;

void func() {
	int l = 1;
	int r = M;
	ll ans = 0;
	while (r <= N) {
		ans = max(ans, dp[r] - dp[l - 1]);
		l++;
		r++;
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