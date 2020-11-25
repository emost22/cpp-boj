#include <iostream>
#include <algorithm>
using namespace std;

int N, M, list[1000001];

int binarysearch(int l, int r, int x) {
	int m = (l + r) / 2;

	if (list[m] == x) return 1;
	else if (list[m] > x) {
		if (l != m) return binarysearch(l, m - 1, x);
	}
	else {
		if (m != r) return binarysearch(m + 1, r, x);
	}

	return 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc, x;
	cin >> tc;
	while (tc--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> list[i];
		}
		sort(list + 1, list + 1 + N);

		cin >> M;
		while (M--) {
			cin >> x;
			cout << binarysearch(1, N, x) << '\n';
		}
	}

	return 0;
}