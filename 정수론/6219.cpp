#include <iostream>
#include <string>
#define MAX 4000001
using namespace std;

bool isNotPrime[MAX];
int l, r, x;

void init() {
	isNotPrime[0] = true;
	isNotPrime[1] = true;
	for (int i = 2; i * i < MAX; i++) {
		if (isNotPrime[i]) continue;

		for (int j = 2; i * j < MAX; j++) {
			isNotPrime[i * j] = true;
		}
	}
}

bool isContainX(int a) {
	while (a) {
		if (a % 10 == x) return true;
		a /= 10;
	}

	return false;
}

void func() {
	init();

	int ret = 0;
	for (int i = l; i <= r; i++) {
		if (isNotPrime[i]) continue;
		ret += isContainX(i);
	}

	cout << ret << '\n';
}

void input() {
	cin >> l >> r >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}