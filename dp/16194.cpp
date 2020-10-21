#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int list[1001], dp[1001];
int N;

void init() {
	for (int i = 1; i <= N; i++) {
		dp[i] = INF;
	}
}

int func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + list[j]);
		}
	}

	return dp[N];
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func() << '\n';

	return 0;
}