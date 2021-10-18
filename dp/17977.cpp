#include <iostream>
#define MAX 1000001
using namespace std;

int dp[MAX];

void init() {
	dp[4] = 1;
	for (int i = 5; i < MAX; i++) {
		dp[i] = dp[(i + 1) / 2] + 2;
	}
}

void input() {
	int N;
	cin >> N;
	cout << dp[N] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}