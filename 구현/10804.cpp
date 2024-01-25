#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;

int list[MAX];
int N;

void func() {
	N = 10;
	int l, r;
	while (N--) {
		cin >> l >> r;
		reverse(list + l - 1, list + r);
	}

	for (int i = 0; i < MAX; i++) {
		cout << list[i] << ' ';
	}
	cout << '\n';
}

void init() {
	for (int i = 0; i < MAX; i++) {
		list[i] = i + 1;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	func();

	return 0;
}