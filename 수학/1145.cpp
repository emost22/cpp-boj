#include <iostream>
#include <algorithm>
#define MAX 5
using namespace std;

int list[MAX];

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

void func() {
	int ret = 1e9;
	for (int i = 0; i < MAX- 2; i++) {
		for (int j = i + 1; j < MAX - 1; j++) {
			int l = lcm(list[i], list[j]);
			for (int k = j + 1; k < MAX; k++) {
				ret = min(ret, lcm(l, list[k]));
			}
		}
	}
	cout << ret << '\n';
}

void input() {
	for (int i = 0; i < MAX; i++) {
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