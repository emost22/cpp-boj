#include <iostream>
#define MAX 100001
using namespace std;

int dp[MAX];
int N, M;

void func() {
	int l, r;
	cin >> M;
	while (M--) {
		cin >> l >> r;
		cout << dp[r + 1] - dp[l] << '\n';
	}
}

void input() {
	cin >> N;
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