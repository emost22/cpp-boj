#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 2147483647
using namespace std;

bool holiday[101];
int dp[101][101];
int N, M;

int func(int day, int cnt) {
	if (day > N) return 0;

	int &ret = dp[day][cnt];
	if (ret != -1) return ret;
	ret = INF;

	if (holiday[day]) ret = func(day + 1, cnt);
	else {
		ret = min(ret, func(day + 1, cnt) + 10000);
		ret = min(ret, func(day + 3, cnt + 1) + 25000);
		ret = min(ret, func(day + 5, cnt + 2) + 37000);

		if (cnt >= 3) ret = min(ret, func(day + 1, cnt - 3));
	}

	return ret;
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		holiday[x] = true;
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(1, 0) << '\n';

	return 0;
}