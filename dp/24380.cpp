#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;

int list[MAX], dp[MAX];
int pre[MAX];
int k, N;

void func() {
	memset(pre, -1, sizeof(pre));
	pre[0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = (dp[i - 1] + list[i]) % k;
		if (!(list[i] % k)) {
			cout << i << '\n';
			return;
		}

		if (pre[dp[i]] != -1) {
			for (int j = pre[dp[i]] + 1; j <= i; j++) {
				cout << j << ' ';
			}
			cout << '\n';
			return;
		}

		pre[dp[i]] = i;
	}
	cout << "no kravaiche\n";
}

void input() {
	cin >> k >> N;
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