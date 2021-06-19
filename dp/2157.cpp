#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1000000000
using namespace std;

int list[301][301], dp[301][301];
int N, M, K;

int func(int idx, int cnt) {
	if (cnt == M && idx != N) return -INF;
	if (idx == N) return 0;

	int &ret = dp[idx][cnt];
	if (ret != -1) return ret;
	ret = -INF;

	for (int i = idx + 1; i <= N; i++) {
		if (!list[idx][i]) continue;

		ret = max(ret, func(i, cnt + 1) + list[idx][i]);
	}

	return ret;
}

void input() {
	int u, v, w;
	cin >> N >> M >> K;
	while (K--) {
		cin >> u >> v >> w;
		list[u][v] = max(list[u][v], w);
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(1, 1) << '\n';

	return 0;
}