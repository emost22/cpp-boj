#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int dp[MAX];
int N;

void init() {
	for (int i = 1; i < MAX; i++) {
		dp[i] = 1;
		for (int j = 0; j < i - 1; j++) {
			if ((i - j) & 1) continue;

			dp[i] += dp[(i - j) >> 1];
		}
	}
}

void input() {
	cin >> N;
	cout << dp[N] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	while (tc--) {
		input();
	}

	return 0;
}