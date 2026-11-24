#include <iostream>
#include <algorithm>
#define MAX 50002
#define MAX_N 1001
using namespace std;

int dp[MAX];
int list[MAX_N];
int N, K;

void func() {
	for (int i = 1; i < MAX; i++) {
		dp[i] = 1e9;
		for (int j = 0; j < N; j++) {
			if (i < list[j]) break;

			dp[i] = min(dp[i], dp[i - list[j]] + 1);
		}

		if (dp[i] > K) {
			if (i & 1) {
				cout << "jjaksoon win at " << i << '\n';
				return;
			}
			else {
				cout << "holsoon win at " << i << '\n';
				return;
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}