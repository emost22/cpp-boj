#include <iostream>
#include <algorithm>
#define MAX 2000001
using namespace std;

int list[MAX];
int palindrome[MAX];
int N, M;

void func() {
	int s, e;
	cin >> M;
	while (M--) {
		cin >> s >> e;
		s = (s - 1) * 2;
		e = (e - 1) * 2;
		int m = (s + e) / 2;

		if (m + palindrome[m] >= e) cout << "1\n";
		else cout << "0\n";
	}
}

void manacher() {
	int p = 0;
	int r = 0;
	for (int i = 0; i < N; i++) {
		if (i <= r) {
			palindrome[i] = min(palindrome[2 * p - i], r - i);
		}
		else {
			palindrome[i] = 0;
		}

		while (i - palindrome[i] - 1 >= 0 && i + palindrome[i] + 1 < N && list[i - palindrome[i] - 1] == list[i + palindrome[i] + 1]) palindrome[i]++;

		if (r < i + palindrome[i]) {
			r = i + palindrome[i];
			p = i;
		}
	}
}

void input() {
	cin >> N;
	N *= 2;
	for (int i = 0; i < N; i += 2) {
		cin >> list[i];
		list[i + 1] = 0;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	manacher();
	func();

	return 0;
}