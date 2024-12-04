#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);

	int lo = 2e9;
	int le = 2e9;
	int odd = 2e9 + 1;
	int even = 2e9 + 1;
	for (int i = 0; i < N; i++) {
		if (list[i] & 1) {
			if (lo != 2e9) even = min(even, list[i] - lo);
			if (le != 2e9) odd = min(odd, list[i] - le);
			lo = list[i];
		}
		else {
			if (le != 2e9) even = min(even, list[i] - le);
			if (lo != 2e9) odd = min(odd, list[i] - lo);
			le = list[i];
		}
	}
	if (odd == 2e9 + 1) odd = -1;
	if (even == 2e9 + 1) even = -1;
	cout << even << ' ' << odd << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}