#include <iostream>
#include <algorithm>
using namespace std;

int house[200000], ans, N, C;

void binarysearch(int s, int e) {
	if (s > e) return;

	int cnt = 1;
	int m = (s + e) / 2;
	int before = house[0];
	for (int i = 1; i < N; i++) {
		if (house[i] - before >= m) {
			cnt++;
			before = house[i];
		}
	}

	if (cnt >= C) {
		ans = m;
		binarysearch(m + 1, e);
	}
	else binarysearch(s, m - 1);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> house[i];
	}
	sort(house, house + N);

	binarysearch(1, house[N - 1] - house[0]);

	cout << ans << '\n';

	return 0;
}