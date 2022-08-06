#include <iostream>
#include <unordered_map>
#define MAX 200001
using namespace std;
typedef long long ll;

int dp[MAX];
int N, K;

void func() {
	unordered_map<int, ll> m;
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] += dp[i - 1];
		if (dp[i] == K) ans++;

		if (m.find(dp[i] - K) != m.end()) {
			ans += m[dp[i] - K];
		}

		if (m.find(dp[i]) != m.end()) {
			m[dp[i]]++;
		}
		else {
			m.insert({ dp[i], 1L });
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}