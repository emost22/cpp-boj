#include <iostream>
using namespace std;

int list[101];
int N, K;

void solve1(int idx) {
	for (int i = idx; i <= N; i += idx) {
		list[i] = 1 - list[i];
	}
}

void solve2(int idx) {
	int l = idx - 1;
	int r = idx + 1;
	list[idx] = 1 - list[idx];
	while (l > 0 && r <= N) {
		if (list[l] == list[r]) {
			list[l] = 1 - list[l];
			list[r] = 1 - list[r];
		}
		else break;

		l--;
		r++;
	}
}

void func() {
	int t, idx;
	cin >> K;
	while (K--) {
		cin >> t >> idx;
		if (t == 1) solve1(idx);
		else solve2(idx);
	}
}

void print() {
	for (int i = 1; i <= N; i++) {
		cout << list[i] << ' ';
		if (!(i % 20)) cout << '\n';
	}
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
	print();

	return 0;
}