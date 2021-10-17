#include <iostream>
#include <algorithm>
#include <string>
#define MAX 101
using namespace std;
typedef long long ll;

ll dp[MAX] = { 0,0,1,7,4,2,6,8,10 };
int N;

void init() {
	for (int i = 9; i < MAX; i++) {
		dp[i] = dp[i - 2] * 10 + dp[2];
		for (int j = 3; j <= 7; j++) {
			if (j != 6) dp[i] = min(dp[i], dp[i - j] * 10 + dp[j]);
			else dp[i] = min(dp[i], dp[i - j] * 10);
		}
	}
}

void input() {
	string maxValue = "";
	cin >> N;
	if (N % 2) {
		maxValue += '7';
		for (int i = 0; i < N - 3; i += 2) {
			maxValue += '1';
		}
	}
	else {
		for (int i = 0; i < N; i += 2) {
			maxValue += '1';
		}
	}

	cout << dp[N] << ' ' << maxValue << '\n';
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