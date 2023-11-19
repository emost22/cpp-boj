#include <iostream>
#define MAX 101
using namespace std;

int dp[MAX];
int N;

void init() {
	for (int i = 1; i < MAX; i += 2) {
		dp[i] = dp[i + 1] = dp[i - 1] + i;
	}
}

void func() {
	cout << dp[N] << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}