#include <iostream>
#define MAX 41
using namespace std;

int dp[MAX];
int N;

void init() {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < MAX; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

void func() {
	cout << dp[N] << '\n';
}

void input() {
	cin >> N;
	if (!N) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	while (1) {
		input();
		func();
	}

	return 0;
}