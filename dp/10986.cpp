#include <iostream>
#define MAX_N 1000001
#define MAX_M 1001
using namespace std;
typedef long long ll;

ll cnt[MAX_M], ans;
int dp[MAX_N];
int N, M;

void func() {
	ans = cnt[0];
	for (int i = 0; i < M; i++) {
		ans += (cnt[i] * (cnt[i] - 1) / 2LL);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];

		dp[i] = (dp[i] + dp[i - 1]) % M;
		cnt[dp[i]]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}