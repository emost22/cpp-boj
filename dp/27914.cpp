#include <iostream>
#define MAX 100001
using namespace std;
typedef long long ll;

ll dp[MAX];
int list[MAX];
int N, K, Q;

void func() {
	ll conn = 0;
	for (int i = 1; i <= N; i++) {
		if (list[i] == K) {
			dp[i] = dp[i - 1];
			conn = 0;
		}
		else conn++;

		dp[i] = dp[i - 1] + conn;
	}

	int x;
	while (Q--) {
		cin >> x;
		cout << dp[x] << '\n';
	}
}

void input() {
	cin >> N >> K >> Q;
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