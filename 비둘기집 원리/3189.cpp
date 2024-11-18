#include <iostream>
#include <string>
using namespace std;

int a, b, c;

void func() {
	int mod = 1;
	for (int i = 0; i < to_string(c).size(); i++) {
		mod *= 10;
	}

	a = (a * b) % mod;
	for (int i = 1; i <= mod; i++) {
		if (a == c) {
			cout << i << '\n';
			return;
		}

		a = (a * b) % mod;
	}

	cout << "NIKAD\n";
}

void input() {
	cin >> a >> b >> c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}