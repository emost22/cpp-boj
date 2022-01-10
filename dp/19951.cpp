#include <iostream>
#define MAX 100002
using namespace std;

int dp[MAX];
int list[MAX];
int N, M;

void func() {
	int l, r, x;
	while (M--) {
		cin >> l >> r >> x;

		dp[l] += x;
		dp[r + 1] -= x;
	}
	
	for (int i = 1; i <= N; i++) {
		dp[i] += dp[i - 1];
		cout << list[i] + dp[i] << ' ';
	}
	cout << '\n';
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