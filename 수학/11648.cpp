#include <iostream>
using namespace std;

int N;

int getNext(int x) {
	int ret = 1;
	while (x) {
		ret *= (x % 10);
		x /= 10;
	}
	return ret;
}

void func() {
	int ret = 0;
	while (N >= 10) {
		N = getNext(N);
		ret++;
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