#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int list[15], idx;
int one[15], oneidx, com[2][15], comidx[2];
int N, M, ans = INF;

int abs(int x) {
	return x > 0 ? x : -x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int K;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		if (list[i]) one[oneidx++] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			if (i % 2 == 0) {
				com[1][comidx[1]++] = idx++;
			}
			else {
				com[0][comidx[0]++] = idx++;
			}
		}
	}

	if (comidx[0] == oneidx) {
		int sum = 0;
		for (int i = oneidx - 1; i >= 0; i--) {
			sum += abs(com[0][i] - one[i]);
		}
		ans = min(ans, sum);
	}
	if (comidx[1] == oneidx) {
		int sum = 0;
		for (int i = oneidx - 1; i >= 0; i--) {
			sum += abs(com[1][i] - one[i]);
		}
		ans = min(ans, sum);
	}

	cout << ans << '\n';

	return 0;
}