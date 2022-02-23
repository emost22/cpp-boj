#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1000
using namespace std;

int list[MAX], dp[MAX];
int N;

void func() {
	int ans = list[0];
	dp[0] = list[0];
	for (int i = 1; i < N; i++) {
		dp[i] = list[i];
		for (int j = 0; j < i; j++) {
			if (list[i] > list[j]) {
				dp[i] = max(dp[i], dp[j] + list[i]);
			}
		}

		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
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