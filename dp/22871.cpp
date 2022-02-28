#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 5001
using namespace std;
typedef long long ll;

ll list[MAX], dp[MAX];
int N;

ll dfs(int x) {
	if (x == N - 1) return 0;

	ll &ret = dp[x];
	if (ret != -1) return ret;
	ret = 1e10;

	for (int i = x + 1; i < N; i++) {
		ret = min(ret, max(dfs(i), (ll)(i - x) * (1LL + abs(list[x] - list[i]))));
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(0) << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
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