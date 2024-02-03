#include <iostream>
using namespace std;

int N;

void func() {
	while (N) {
		int n = N;
		bool flag = true;
		while (n) {
			if (n % 10 != 4 && n % 10 != 7) {
				flag = false;
				break;
			}
			n /= 10;
		}

		if (flag) {
			cout << N << '\n';
			return;
		}

		N--;
	}
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