#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX], dp[MAX];
int N;

void func() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = list[i];
		for (int j = 1; j < i; j++) {
			if (list[i] >= list[j]) continue;
			dp[i] = max(dp[i], dp[j] + list[i]);
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
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