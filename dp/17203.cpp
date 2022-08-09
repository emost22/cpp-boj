#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX], dp[MAX];
int N, M;

void func() {
	int l, r;
	while (M--) {
		cin >> l >> r;
		cout << (r - 1 < l ? 0 : dp[r] - dp[l]) << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		dp[i] = dp[i - 1] + abs(list[i] - list[i - 1]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}