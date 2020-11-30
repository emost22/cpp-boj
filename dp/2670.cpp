#include <iostream>
#include <algorithm>
using namespace std;

int N;
double list[10001], dp[10001];

void func() {
	double ans = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = max(list[i] * dp[i - 1], list[i]);
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
	cout << fixed; cout.precision(3);

	input();
	func();

	return 0;
}