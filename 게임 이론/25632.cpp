#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int prime[MAX];
int l1, r1, l2, r2;

void init() {
	for (int i = 2; i * i < MAX; i++) {
		if (prime[i]) continue;

		for (int j = 2; i * j < MAX; j++) {
			if (prime[i * j]) continue;
			prime[i * j] = true;
		}
	}
}

void func() {
	init();

	int cnt1 = 0;
	for (int i = l1; i <= r1; i++) {
		cnt1 += !prime[i];
	}

	int cnt2 = 0;
	for (int i = l2; i <= r2; i++) {
		cnt2 += !prime[i];
	}

	int common = 0;
	for (int i = max(l1, l2); i <= min(r1, r2); i++) {
		common += !prime[i];
	}

	if (common & 1) {
		if (cnt1 >= cnt2) cout << "yt\n";
		else cout << "yj\n";
	}
	else {
		if (cnt1 > cnt2) cout << "yt\n";
		else cout << "yj\n";
	}
}

void input() {
	cin >> l1 >> r1 >> l2 >> r2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}