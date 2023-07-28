#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int list[MAX];
int N, M;

void init() {
	for (int i = 1; i <= N; i++) {
		list[i] = i;
	}
}

void func() {
	init();

	int l, r;
	while (M--) {
		cin >> l >> r;
		reverse(list + l, list + r + 1);
	}

	for (int i = 1; i <= N; i++) {
		cout << list[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}