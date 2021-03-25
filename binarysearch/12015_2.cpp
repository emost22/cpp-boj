#include <iostream>
using namespace std;

int lis[1000001];
int list[1000001];
int N, ans;

int binarySearch(int l, int r, int x) {
	while (l < r) {
		int m = (l + r) / 2;

		if (lis[m] >= x) r = m;
		else l = m + 1;
	}

	return r;
}

void func() {
	int idx = 0;
	lis[++idx] = list[1];
	for (int i = 2; i <= N; i++) {
		if (lis[idx] < list[i]) {
			lis[++idx] = list[i];
		}
		else {
			int tmp = binarySearch(1, idx, list[i]);

			lis[tmp] = list[i];
		}
	}

	ans = idx;
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	cout << ans << '\n';

	return 0;
}