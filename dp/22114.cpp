#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;

int list[MAX], dp[MAX][2];
int N, K;

int solve(int idx, int cnt) {
	if (cnt == 2) return 0;
	if (idx == N - 1) return 1;

	int& ret = dp[idx][cnt];
	if (ret != -1) return ret;
	ret = 1;

	if (list[idx] <= K) {
		ret = max(ret, solve(idx + 1, cnt) + 1);
	}
	else {
		ret = max(ret, solve(idx + 1, cnt + 1) + 1);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	int ret = 0;
	for (int i = 0; i < N - 1; i++) {
		ret = max(ret, solve(i, 0));
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
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