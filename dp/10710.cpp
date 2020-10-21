#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int dp[1001][1001], usemin[1001][2], d[1001], c[1001];
int N, M, turn;

int func() {
	for (int i = 1; i <= N; i++) {
		usemin[i - 1][turn % 2] = INF;
		for (int j = i; j - i <= M - N; j++) {
			if (i == 1) dp[i][j] = d[i] * c[j];
			else dp[i][j] = usemin[j - 1][(turn + 1) % 2] + d[i] * c[j];
			usemin[j][turn % 2] = min(usemin[j - 1][turn % 2], dp[i][j]);
		}
		turn++;
	}

	return usemin[M][(turn + 1) % 2];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> d[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> c[i];
	}

	cout << func() << '\n';

	return 0;
}