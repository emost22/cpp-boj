#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;

int list[MAX], dp[MAX];
int N;

void func(int tc) {
	int lis = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (list[i] > list[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		lis = max(lis, dp[i] + 1);
	}

	cout << "Case #" << tc << ": " << N - lis << '\n';
	memset(dp, 0, sizeof(dp));
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}