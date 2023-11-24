#include <iostream>
#include <algorithm>
#define MAX 300001
using namespace std;
typedef long long ll;

ll dp[MAX];
int N, M;

void func() {
	sort(dp + 1, dp + 1 + N, [](ll a, ll b) {
		return a > b;
	});

	ll ret = 0;
	for (int i = 1; i <= M; i++) {
		ret += dp[i];
	}

	cout << ret << '\n';
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