#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;
typedef long long ll;

ll dp[MAX];
int N, M;

void func() {
	int l = 1;
	int r = 1;
	ll ret = 0;
	while (r <= N) {
		if (dp[r] - dp[l - 1] <= M) {
			ret = max(ret, dp[r] - dp[l - 1]);
			r++;
		}
		else {
			if (l == r) r++;
			l++;
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}