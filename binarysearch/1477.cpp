#include <iostream>
#include <algorithm>
#define MAX 53
using namespace std;

int list[MAX];
int N, M, L;

void func() {
	int l = 1;
	int r = L;
	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;

		int sum = 0;
		for (int i = 1; i < N; i++) {
			sum += ((list[i] - list[i - 1] - 1) / m);
		}

		if (sum <= M) {
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
	cin >> N >> M >> L;
	list[0] = 0;
	list[1] = L;
	N += 2;
	for (int i = 2; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}