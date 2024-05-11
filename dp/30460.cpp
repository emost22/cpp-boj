#include <iostream>
#include <algorithm>
#define MAX 200003
using namespace std;

int list[MAX];
int dp[MAX];
int N;

void func() {
	dp[1] = list[1];
	dp[2] = dp[1] + list[2];
	for (int i = 3; i <= N + 2; i++) {
		dp[i] = max(dp[i - 1] + list[i], dp[i - 3] + ((list[i] + list[i - 1] + list[i - 2]) << 1));
	}

	cout << dp[N + 2] << '\n';
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