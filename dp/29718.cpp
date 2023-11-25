#include <iostream>
#include <algorithm>
#define MAX 2001
using namespace std;

int dp[MAX];
int N, M, A;

void func() {
	for (int i = 1; i <= M; i++) {
		dp[i] += dp[i - 1];
	}

	int l = 1;
	int r = A;
	int ret = 0;
	while (r <= M) {
		ret = max(ret, dp[r] - dp[l - 1]);
		r++;
		l++;
	}

	cout << ret << '\n';
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> x;
			dp[j] += x;
		}
	}
	cin >> A;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}