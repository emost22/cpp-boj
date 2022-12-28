#include <iostream>
#define MAX 1000001
using namespace std;

int dp[MAX];
int N, M;

void func() {
	int ret = 0;
	int s, e;
	while (M--) {
		cin >> s >> e;
		ret ^= (dp[e] ^ dp[s - 1]);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
		dp[i] ^= dp[i - 1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}