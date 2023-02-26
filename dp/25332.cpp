#include <iostream>
#include <unordered_map>
#define MAX 200001
using namespace std;
typedef long long ll;

unordered_map<int, ll> m;
int arrList[MAX], dp[MAX];
int N;

void func() {
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		if (!dp[i]) ans++;

		if (m.find(dp[i]) != m.end()) {
			ans += m[dp[i]]++;
		}
		else {
			m.insert({ dp[i], 1LL });
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arrList[i];
	}

	int x;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		dp[i] = dp[i - 1] + arrList[i] - x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}