#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

typedef struct Point {
	int l;
	int r;
	int x;
}Point;

int dp[MAX];
Point list[MAX];
int N;

void func() {
	int ans = 0;
	dp[0] = list[0].x;
	dp[1] = list[1].x;
	
	ans = dp[0];
	for (int i = 2; i < N; i++) {
		dp[i] = list[i].x + ans;
		ans = max(ans, dp[i - 1]);
	}
	ans = max(ans, dp[N - 1]);

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].l >> list[i].r >> list[i].x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}