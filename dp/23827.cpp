#include <iostream>
#include <algorithm>
#define MAX 500001
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll list[MAX], dp[MAX];
int N;

void func() {
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = (ans + list[i] * (dp[N] - dp[i])) % MOD;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		dp[i] = dp[i - 1] + list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}