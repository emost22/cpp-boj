#include <iostream>
using namespace std;

int list[1001], num[1001];
int L, N;

void func() {
	int maxlength = 0;
	int maxidx = 0;
	for (int i = 1; i <= N; i++) {
		if (maxlength < num[i]) {
			maxlength = num[i];
			maxidx = i;
		}
	}

	cout << maxidx << '\n';
}

void input() {
	int maxlength = 0;
	int maxidx = 0;
	int l, r;
	cin >> L >> N;
	for (int i = 1; i <= N; i++) {
		cin >> l >> r;
		if (maxlength < r - l) {
			maxlength = r - l;
			maxidx = i;
		}

		for (int j = l; j <= r; j++) {
			if (list[j]) continue;
			list[j] = i;
			num[i]++;
		}
	}

	cout << maxidx << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}