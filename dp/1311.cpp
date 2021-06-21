#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 20
#define INF 1000000000
using namespace std;

int list[MAX][MAX], dp[MAX][1 << MAX];
int N, chk;

int func(int x, int cost) {
	if (x == N) {
		if(cost == chk) return 0;
		else return INF;
	}

	int &ret = dp[x][cost];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 0; i < N; i++) {
		if (cost & (1 << i)) continue;

		ret = min(ret, func(x + 1, cost | (1 << i)) + list[x][i]);
	}

	return ret;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	chk = (1 << N) - 1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(0, 0) << '\n';

	return 0;
}