#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

int dp[MAX][13];
int N;

int func(int idx, int type) {
	if (idx == 0) {
		if (type == 0) return 1;
		else return 0;
	}
	else if (idx < 0) return 0;

	int &ret = dp[idx][type];
	if (ret != -1) return ret;
	ret = 0;

	if (!type) {
		ret += func(idx - 1, 0);
		ret += func(idx - 1, 3);
		ret += func(idx - 1, 9);
		ret += func(idx - 1, 12);
		ret += func(idx - 2, 0);
	}
	else if (type == 3) {
		ret += func(idx - 1, 0);
		ret += func(idx - 1, 12);
	}
	else if (type == 6) {
		ret += func(idx - 1, 9);
	}
	else if (type == 9) {
		ret += func(idx - 1, 0);
		ret += func(idx - 1, 6);
	}
	else {
		ret += func(idx - 1, 0);
		ret += func(idx - 1, 3);
	}

	return ret;
}

void init() {
	memset(dp, -1, sizeof(dp));
}

void input() {
	cin >> N;
	cout << func(N, 0) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	init();
	while (tc--) {
		input();
	}

	return 0;
}