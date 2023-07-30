#include <iostream>
#define MAX 1000001
using namespace std;

int dp[MAX];
int N, M;

void func() {
	for (int i = 1; i < MAX; i++) {
		dp[i] += dp[i - 1];
	}

	int x;
	cin >> M;
	while (M--) {
		cin >> x;
		cout << dp[x] << '\n';
	}
}

void input() {
	int l, r;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> l >> r;
		dp[l]++;
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