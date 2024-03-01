#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int dp[MAX];
int N, M;

void init() {
	for (int i = 1; i <= N; i++) {
		dp[i] = 1e9;
	}
}

void func() {
	init();

	for (int i = 0; i <= N; i++) {
		if (i + 1 <= N) {
			dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		}
		
		if (i + (i >> 1) <= N) {
			dp[i + (i >> 1)] = min(dp[i + (i >> 1)], dp[i] + 1);
		}
	}

	cout << (dp[N] <= M ? "minigimbob\n" : "water\n");
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}