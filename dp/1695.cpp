#include <iostream>
#define max(a, b) {a > b ? a : b}
using namespace std;

int dp[2][5001], list[5001];
int N;

void func() {
	int t = 0;
	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= N; j++) {
			if (list[i] == list[j]) {
				dp[t][j] = dp[1 - t][j - 1] + 1;
			}
			else dp[t][j] = max(dp[1 - t][j], dp[t][j - 1]);
		}
		t = 1 - t;
	}
	
	cout << N - dp[1 - t][N] << '\n';
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