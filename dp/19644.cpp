#include <iostream>
#include <algorithm>
#define MAX 3000001
using namespace std;

int list[MAX];
int dp[MAX];
int N, L, K, C;

void func() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int l = max(0, i - L);
		if (K + dp[i - 1] - dp[l] >= list[i]) {
			dp[i] = dp[i - 1] + K;
		}
		else {
			cnt++;
			dp[i] = dp[i - 1];
			if (cnt > C) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

void input() {
	cin >> N >> L >> K >> C;
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