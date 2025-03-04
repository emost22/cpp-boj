#include <iostream>
#define MAX 101
using namespace std;

int dp[MAX];
int A, B, C;

void func() {
	for (int i = 1; i < MAX; i++) {
		dp[i] += dp[i - 1];
	}

	int ret = 0;
	for (int i = 1; i < MAX; i++) {
		if (!dp[i]) continue;
		
		if (dp[i] == 1) ret += A;
		else if (dp[i] == 2) ret += (B << 1);
		else ret += (C * 3);
	}
	cout << ret << '\n';
}

void input() {
	int x, y;
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		cin >> x >> y;
		dp[x]++;
		dp[y]--;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}