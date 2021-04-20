#include <iostream>
using namespace std;
typedef long long ll;

ll dp[36];
int N;

void func() {
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}

	cout << dp[N] << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}