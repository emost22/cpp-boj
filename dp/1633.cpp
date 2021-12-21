#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1000
#define MAXCNT 15
using namespace std;

int dp[MAX][MAXCNT + 1][MAXCNT + 1];
int list[MAX][2];
int N;

int dfs(int idx, int b, int w) {
	if (b == MAXCNT && w == MAXCNT) return 0;
	if (idx == N) return -1e9;
	
	int &ret = dp[idx][b][w];
	if (ret != -1) return ret;
	
	ret = dfs(idx + 1, b, w);
	if (b < MAXCNT) ret = max(ret, dfs(idx + 1, b + 1, w) + list[idx][1]);
	if (w < MAXCNT) ret = max(ret, dfs(idx + 1, b, w + 1) + list[idx][0]);

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0, 0) << '\n';
}

void input() {
	int x, y;
	while (cin >> x) {
		cin >> y;
		list[N][0] = x;
		list[N++][1] = y;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}