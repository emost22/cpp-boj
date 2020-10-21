#include <iostream>
#include <cstring>
using namespace std;

int dp[32769][182][4];

int func(int N, int now, int cnt) {
	if (!N) return 1;

	if (now == 182 || cnt == 4) return 0;

	if (dp[N][now][cnt] != -1) return dp[N][now][cnt];

	dp[N][now][cnt] = func(N, now + 1, cnt);

	if (N >= now * now) dp[N][now][cnt] += func(N - now * now, now, cnt + 1);

	return dp[N][now][cnt];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	memset(dp, -1, sizeof(dp));

	while (1) {
		cin >> N;
		if (!N) break;

		cout << func(N, 1, 0) << '\n';
	}

	return 0;
}