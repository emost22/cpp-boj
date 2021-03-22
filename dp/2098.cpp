#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1000000000
using namespace std;

int list[16][16], dp[16][1 << 16];
int N, allvisit;

int tsp(int v, int visit) {
	if (visit == allvisit) {
		if (list[v][0]) return list[v][0];
		else return INF;
	}

	int &ret = dp[v][visit];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 1; i < N; i++) {
		if (visit & (1 << i) || !list[v][i]) continue;

		ret = min(ret, tsp(i, visit | (1 << i)) + list[v][i]);
	}

	return ret;
}

void input() {
	cin >> N;
	allvisit = (1 << N) - 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << tsp(0, 1) << '\n';

	return 0;
}