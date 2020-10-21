#include <iostream>
using namespace std;

int list[10001], N, M, max_q, sum, ans;

int Max(int x, int y) {
	return x > y ? x : y;
}

void binarysearch(int s, int e) {
	if (s > e) return;

	int m = (s + e) / 2;
	sum = 0;

	for (int i = 1; i <= N; i++) {
		if (list[i] <= m) {
			sum += list[i];
		}
		else sum += m;
	}

	if (sum <= M) {
		ans = Max(ans, m);
		binarysearch(m + 1, e);
	}
	else binarysearch(s, m - 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		max_q = Max(max_q, list[i]);
		sum += list[i];
	}
	cin >> M;

	if (sum <= M) {
		cout << max_q << '\n';
		return 0;
	}

	binarysearch(1, max_q);

	cout << ans << '\n';

	return 0;
}