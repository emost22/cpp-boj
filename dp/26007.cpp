#include <iostream>
#define MAX 100001
using namespace std;

int dp[MAX];
int N, M, K, X;

void func() {
	int l, r;
	while (M--) {
		cin >> l >> r;
		cout << dp[r - 1] - dp[l - 1] << '\n';
	}
}

void input() {
	int y;
	cin >> N >> M >> K >> X;
	for (int i = 1; i <= N; i++) {
		cin >> y;
		X += y;
		dp[i] = dp[i - 1] + (X < K);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}