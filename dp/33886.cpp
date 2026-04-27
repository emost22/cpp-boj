#include <iostream>
#include <algorithm>
#define MAX 3001
using namespace std;

int list[MAX];
int dp[MAX];
int N;

void func() {
	for (int i = 1; i <= N; i++) {
		dp[i] = 1e9;
		for (int j = 1; j <= i; j++) {
			if (i - j + 1 > list[j]) continue;

			dp[i] = min(dp[i], dp[j - 1] + 1);
		}
	}

	cout << dp[N] << '\n';
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