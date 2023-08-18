#include <iostream>
using namespace std;

int N, d;

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		int n = i;
		while (n) {
			ret += (n % 10 == d);
			n /= 10;
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> d;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}