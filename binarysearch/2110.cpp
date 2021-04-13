#include <iostream>
#include <algorithm>
using namespace std;

int list[200001];
int N, M;

bool solve(int length) {
	int pre = list[1];
	int cnt = 1;
	for (int i = 2; i <= N; i++) {
		if (list[i] - pre >= length) {
			cnt++;
			pre = list[i];
		}
	}

	if (cnt >= M) return true;
	else return false;
}

int binarySearch(int l, int r) {
	int ans = 0;

	while (l <= r) {
		int m = (l + r) / 2;
		if (solve(m)) {
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}

	return ans;
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	sort(list + 1, list + 1 + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << binarySearch(1, list[N] - list[1]) << '\n';

	return 0;
}