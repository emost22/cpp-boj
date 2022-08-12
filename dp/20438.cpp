#include <iostream>
#define MAX 5004
using namespace std;

int dp[MAX];
bool sleep[MAX], attend[MAX];
int N, K, Q, M;

void func() {
	for (int i = 3; i <= N + 2; i++) {
		dp[i] = dp[i - 1] + (!attend[i] ? 1 : 0);
	}

	int l, r;
	while (M--) {
		cin >> l >> r;
		cout << dp[r] - dp[l - 1] << '\n';
	}
}

void input() {
	int x;
	cin >> N >> K >> Q >> M;
	while (K--) {
		cin >> x;
		sleep[x] = true;
	}

	while (Q--) {
		cin >> x;
		if (sleep[x]) continue;

		for (int i = x; i <= N + 2; i += x) {
			if (sleep[i]) continue;

			attend[i] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}