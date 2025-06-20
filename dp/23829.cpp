#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

ll list[MAX];
ll dp[MAX];
int N, M;

void init() {
	sort(list + 1, list + 1 + N);
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + list[i];
	}
}

void func() {
	init();

	ll pos;
	while (M--) {
		cin >> pos;

		ll m = lower_bound(list + 1, list + 1 + N, pos) - list;
		cout << (m - 1LL) * pos - (dp[m - 1] << 1) + dp[N] - (N - m + 1LL) * pos << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
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