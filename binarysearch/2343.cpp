#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N, M, maxLength;

void func() {
	int l = maxLength;
	int r = N * maxLength;
	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;

		int sum = 0;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			if (sum + list[i] > m) {
				cnt++;
				sum = 0;
			}

			sum += list[i];
		}

		if (cnt <= M) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		maxLength = max(maxLength, list[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}