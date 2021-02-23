#include <iostream>
#include <algorithm>
using namespace std;

int list[1001], num[1001];
int L, N;

void func() {
	int ans = 0, ansidx = 0;
	for (int i = 1; i <= L; i++) {
		if (!list[i]) continue;
		num[list[i]]++;
	}

	for (int i = 1; i <= N; i++) {
		if (ans < num[i]) {
			ans = num[i];
			ansidx = i;
		}
	}

	cout << ansidx << '\n';
}

void input() {
	int maxidx = 0, maxe = 0;
	int l, r;
	cin >> L >> N;
	for (int i = 1; i <= N; i++) {
		cin >> l >> r;
		if (maxe < r - l) {
			maxe = r - l;
			maxidx = i;
		}
		for (int j = l; j <= r; j++) {
			if (list[j]) continue;
			list[j] = i;
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