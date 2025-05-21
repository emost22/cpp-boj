#include <iostream>
using namespace std;

int N;

int getSepar(int x) {
	int ret = 0;
	while (x) {
		ret += (x % 10);
		x /= 10;
	}
	return ret;
}

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		int x = getSepar(i);
		ret += (i % x == 0);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}