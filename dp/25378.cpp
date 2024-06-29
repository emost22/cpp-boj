#include <iostream>
#include <algorithm>
#define MAX 2501
using namespace std;

int dp[MAX];
int list[MAX];
int N;

void func() {
	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i], dp[i - 1]);
		int r = list[i];
		for (int j = i + 1; j <= N; j++) {
			r = list[j] - r;

			if (r < 0) break;
			if (!r) dp[j] = max(dp[j], dp[i - 1] + 1);
		}
	}

	cout << N - dp[N] << '\n';
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