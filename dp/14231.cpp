#include <iostream>
#include <algorithm>
#define MAX 5001
using namespace std;

int list[MAX], dp[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (list[i] > list[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}

			ret = max(ret, dp[i]);
		}
	}

	cout << ret << '\n';
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

	input();
	func();

	return 0;
}