#include <iostream>
using namespace std;

int X, Y, N;

bool isDivisible(int x, int y) {
	return x % y == 0;
}

void func() {
	for (int i = 1; i <= N; i++) {
		bool xd = isDivisible(i, X);
		bool yd = isDivisible(i, Y);
		if (xd && yd) cout << "FizzBuzz\n";
		else if (xd) cout << "Fizz\n";
		else if (yd) cout << "Buzz\n";
		else cout << i << '\n';
	}
}

void input() {
	cin >> X >> Y >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}