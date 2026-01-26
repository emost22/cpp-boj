#include <iostream>
using namespace std;

int p, c;

void func() {
	cout << p * 50 - c * 10 + (p > c ? 500 : 0) << '\n';

}

void input() {
	cin >> p >> c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}