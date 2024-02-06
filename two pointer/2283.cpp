#include <iostream>
#define MAX 1000002
using namespace std;

int dp[MAX];
int N, M;

void func() {
	for (int i = 2; i < MAX; i++) {
		dp[i] += dp[i - 1];
	}

	int l = 1;
	int r = 1;
	int sum = 0;
	while (r < MAX) {
		if (sum == M) {
			cout << l - 1 << ' ' << r - 1 << '\n';
			return;
		}

		if (sum < M) {
			sum += dp[r];
			r++;
		}
		else {
			sum -= dp[l];
			l++;
		}
	}

	cout << "0 0\n";
}

void input() {
	int l, r;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> l >> r;
		dp[l + 1]++;
		dp[r + 1]--;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}