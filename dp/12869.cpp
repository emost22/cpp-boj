#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 2147483647
using namespace std;

int dp[61][61][61];
int list[3];
int N;

int sub(int x, int y) {
	return x > y ? x - y : 0;
}

int func(int hp1, int hp2, int hp3) {
	if (!hp1 && !hp2 && !hp3) return 0;
	
	int &ret = dp[hp1][hp2][hp3];
	if (ret != -1) return ret;
	ret = INF;

	if (hp1) {
		ret = min(ret, func(sub(hp1, 9), sub(hp2, 3), sub(hp3, 1)) + 1);
		ret = min(ret, func(sub(hp1, 9), sub(hp2, 1), sub(hp3, 3)) + 1);
	}

	if (hp2) {
		ret = min(ret, func(sub(hp1, 3), sub(hp2, 9), sub(hp3, 1)) + 1);
		ret = min(ret, func(sub(hp1, 1), sub(hp2, 9), sub(hp3, 3)) + 1);
	}

	if (hp3) {
		ret = min(ret, func(sub(hp1, 3), sub(hp2, 1), sub(hp3, 9)) + 1);
		ret = min(ret, func(sub(hp1, 1), sub(hp2, 3), sub(hp3, 9)) + 1);
	}

	return ret;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(list[0], list[1], list[2]) << '\n';

	return 0;
}