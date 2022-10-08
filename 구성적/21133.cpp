#include <iostream>
#define repf(i, l, r) for (int i = l; i <= r; i += 2) cout << i << '\n';
using namespace std;

int N;

void func() {
	if (N % 6 == 2) {
		repf(i, 2, N);
		cout << "3\n1\n";
		repf(i, 7, N);
		cout << "5\n";
	}
	else if (N % 6 == 3) {
		repf(i, 4, N);
		cout << "2\n";
		repf(i, 5, N);
		cout << "1\n3\n";
	}
	else {
		repf(i, 2, N);
		repf(i, 1, N);
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