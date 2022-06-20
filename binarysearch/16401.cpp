#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int list[MAX];
int N, M, maxLength;

void func() {
	int l = 1;
	int r = maxLength;
	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;

		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += (list[i] / m);
		}

		if (sum >= M) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> M >> N;
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