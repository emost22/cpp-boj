#include <iostream>
#include <algorithm>
using namespace std;

int list[4][4000], sum1[16000000], sum2[16000000];
int N;
long long ans;

void init() {
	int s_index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum1[s_index++] = list[0][i] + list[1][j];
		}
	}

	s_index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum2[s_index++] = list[2][i] + list[3][j];
		}
	}
}

void binarysearch(int p, int s, int e) {
	if (s > e) return;

	int m = (s + e) / 2;

	if (p + sum2[m] == 0) {
		ans += upper_bound(sum2, sum2 + N * N, sum2[m]) - lower_bound(sum2, sum2 + N * N, sum2[m]);
	}
	else if (p + sum2[m] > 0) {
		binarysearch(p, s, m - 1);
	}
	else binarysearch(p, m + 1, e);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[0][i] >> list[1][i] >> list[2][i] >> list[3][i];
	}

	init();
	sort(sum2, sum2 + N * N);
	for (int i = 0; i < N * N; i++) {
		binarysearch(sum1[i], 0, N * N - 1);
	}

	cout << ans << '\n';

	return 0;
}