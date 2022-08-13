#include <iostream>
#define MAX 100001
using namespace std;

int dp[MAX];
int list[MAX];
int N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		dp[i] += dp[i - 1];
	}

	int l, r;
	cin >> M;
	while (M--) {
		cin >> l >> r;
		cout << dp[r] - dp[l] << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		if (list[i] < list[i - 1]) dp[i] = 1;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}