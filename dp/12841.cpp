#include <iostream>
#define MAX 100001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

pii dp[MAX];
ll cross[MAX];
int N;

void func() {
	int idx = 0;
	ll ret = 1e12;
	for (int i = 1; i <= N; i++) {
		ll sum = cross[i] + dp[i - 1].first + dp[N - 1].second - dp[i - 1].second;
		if (ret > sum) {
			idx = i;
			ret = sum;
		}
	}

	cout << idx << ' ' << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cross[i];
	}

	for (int i = 1; i < N; i++) {
		cin >> dp[i].first;
		dp[i].first += dp[i - 1].first;
	}

	for (int i = 1; i < N; i++) {
		cin >> dp[i].second;
		dp[i].second += dp[i - 1].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}